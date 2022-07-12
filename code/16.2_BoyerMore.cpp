#include <iostream>
#include <string>
#include <algorithm>

using namespace std; // n là do dai van ban T,m length P

void lastOccurrence(string T,string P,long int n,long int m,long int L[]) 
{
	for(long int i=0;i<n;i++)
	{
		L[T[i]]=-1;
	}
	for(long int i=0;i<m;i++)
	{
		L[P[i]]=i;
	}
}
void boyerMoore(string T,string P)
{
	long int i,j,n,m,dau =0;
	n = T.length();
	long int L[1000];
	m = P.length();
	lastOccurrence(T,P,n,m,L);
	int dem=0,l=0;
	i=m-1;
	j=m-1;
	while(i<n)
	{
		l++;
		if(T[i]==P[j])
		{
			dem++;
			if(dem==m)
			{
				cout<<"Su xuat hien cua mau \""<<P<<"\" trong van ban \""<<T<<"\" co vi tri bat dau la "<<i;
				cout<<"\nSo phep lap la "<<l<<":";
				cout<<"\n   T va P";
				dau=1;
				break;
			}
			i-=1;
			j-=1;
		}
		else
		{
			int k; k=min(j, 1+L[T[i]]);
			i=i+m-k;
			j=m-1;
			dem=0;
		}
	}
	if(dau==0)
	{
		cout<<"Mau \""<<P<<"\" khong xuat hien trong van ban \""<<T<<"\"";
		cout<<"\nSo phep lap la "<<l<<":";
		cout<<"\n   T va P";
	}
	dem=0;
	l=0;
	i=m-1;
	j=m-1;
	while(i<n)
	{
		l++;
		cout<<"\n"<<l<<": "<<T[i]<<" va "<<P[j];
		if(T[i]==P[j])
		{
			dem++;
			if(dem==m)
			{
				break;
			}
			i-=1;
			j-=1;
		}
		else
		{
			int k; k=min(j, 1+L[T[i]]);
			i=i+m-k;
			j=m-1;
			dem=0;
		}
	}
	
}
int main()
{
	string T,P;
	getline(cin, P);
	fflush(stdin);
	getline(cin, T);
	boyerMoore(T,P);
}
