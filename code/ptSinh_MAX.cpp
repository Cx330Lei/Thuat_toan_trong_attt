#include <iostream>
#include<math.h>
using namespace std;
int thuatToanBinhPhuongCoLap(long long int a,long long int k,long long int n)
{
	long long int B[100],A,e,b;
	int t=0;
	b=1;
	if(k==0)
	{
		return b;
	}
	while(k>0)
	{
		B[t]=k%2;
		k=k/2;
		t++;
	} 
	if(B[0]==1)
	{
		b=a;
	}
	for(int i=1;i<t;i++)
	{
		
		A=a*a;
		a=A%n;
		if(B[i]==1)
		{
			e=a*b;
			b=e%n;
		}
	}
	return b;
}
int main()
{
	//Z* n, loga cua b, t la de thu
	int n,a,pi,t;
	cout<<"Nhap n:";
	cin>>n;
	cout<<"\nNhap a:";
	cin>>a;
	cout<<"\nNhap pi:";
	cin>>pi;
	cout<<"\nNhap t:";
	cin>>t;
	for(int i =1; i<=pi;i++)
	{
		int k = thuatToanBinhPhuongCoLap(a,i,n);
		cout<<"\nlog "<<i<<" =  "<<k;
		if(k == t)
		{
			cout<<"\nKq "<<i;
		}
	}
}
