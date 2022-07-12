#include <iostream>
#include <math.h>
#include <cstdlib>

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
void fermat(long long int n,int t)
{
	int k,r,j=0;
	long long int a;
	int C[t+1];					
	a=n-1;
	for(int i=1;i<=t;i++)
	{
		cin>>C[i];
	}
	cout<<"Kiem tra so nguyen n="<<n<<":"<<endl;
	for(int i=1;i<=t;i++)
	{
		k = C[i];
		r = thuatToanBinhPhuongCoLap(k,a,n);
		if(r!=1)
		{
			cout<<"Co so a="<<k<<": Hop so"<<endl;
			j++;
		}
		else
		{
			cout<<"Co so a="<<k<<": Nguyen to"<<endl;
		}
	}
	if(j>0)
	{
		cout<<n<<" la hop so";
	}
	else
	{
		cout<<n<<" co the la nguyen to";
	}
}
int main()
{
	long long int n;
	int t;
	cin>>n;						
	cin>>t;	
	fermat(n,t);
}
