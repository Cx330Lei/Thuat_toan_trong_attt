#include <iostream>
#include <math.h>

using namespace std;
int la_NT(long long int n)
{
	if(n<2)
	{
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
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
int gcd (long long int a,long long int b)
{
	while(a!=b)
	{
		if(a>b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return a;
}
int ktCarmichael(long long int n)
{
	int u,k=0;
	long long int r;
	r=n-1; 
	if(la_NT(n)==1)
	{
		return 0;
	}
	for(long long int i=2;i<n;i++)
	{
		if(gcd(i,n)==1)
		{
			u=thuatToanBinhPhuongCoLap(i,r,n);
			if(u!=1)
			{
				return 0;
			}
		}
	}
	return 1;
}


void lietKeCarmichael(long long int n)
{
	int k;
	for(long long int i=3;i<=n;i++)
	{
		k=ktCarmichael(i);
		if(k==1)
		{
			cout<<i<<"   ";
		}
	}
}
int main()
{
	long long int n;
	cin>>n;								
	lietKeCarmichael(n);
}
