#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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
	long int i,j,n,m;
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
				cout<<"Su xuat hien cua mau \""<<P<<"\" trong van ban \""<<T<<"\" co vi tri bat dau la "<<i<<endl;
				exit(0);
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
	cout<<"Mau \""<<P<<"\" khong xuat hien trong van ban \""<<T<<"\""<<endl;
}
int main()
{
	string T,P;
	cout<<"Nhap chuoi mau P: ";
	getline(cin, P);
	fflush(stdin);
	cout<<"Nhap chuoi van ban T: ";
	getline(cin, T);
	boyerMoore(T,P);
}
