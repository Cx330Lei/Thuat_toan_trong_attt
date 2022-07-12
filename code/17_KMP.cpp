#include <iostream>
#include <string>

using namespace std;
void failure(string P,int n,int L[])
{
	int dem=0;
	L[0]=-1;
	L[1]=0;
	for(int j=2;j<n;j++)
	{				
		int k; k = j-1;		 
		int i=1;		
		while(k>=1)
		{
			if(P.substr(0,k)==P.substr(i,k))	
			{
				L[j]=k;	      
				dem++;					
				break;
			}
			i++;
			k--;	
		}
		if(dem==0)
		{
			L[j]=0;
		}
	}
}

void kMP(string P,string T) 
{
	int j=0,i=0,dem=0,k=0,L[1000],n,m;
	n = P.length();
	m = T.length();
	failure(P,n,L);
	while(i<m)
	{
		k++;
		cout<<k<<": "<<T[i]<<" va "<<P[j]<<endl;
		if(T[i]==P[j])
		{
			dem++;
			if(dem==n)
			{
				cout<<"Su xuat hien cua mau \""<<P<<"\" trong van ban \""<<T<<"\" co vi tri bat dau la "<<i-n+1<<endl;
				cout<<"So phep lap la "<<k;
				exit(0);
			}
			i++;
			j++;
		}
		else
		{
			i=i+j-L[j]-dem;	//ma i la so i ban dau khong tinh i bi tang trong qua trinh trung khop
			j=L[j];
			if(j==-1)
			{
				j=0;
			}
			dem=0;
		}
	}
	cout<<"Mau \""<<P<<"\" khong xuat hien trong van ban \""<<T<<endl;
	cout<<"So phep lap la "<<k<<":";
}
int main()
{
	string P,T;
	cout<<"Nhap chuoi P:";
	getline(cin, P);
	fflush(stdin);
	cout<<"Nhap chuoi T: ";
	getline(cin, T);
	kMP(P,T);
}
