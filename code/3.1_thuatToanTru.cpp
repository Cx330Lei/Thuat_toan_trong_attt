#include <iostream>
#include <math.h>

using namespace std;

void chuyenSoSangMang(int t,int w,long long int a,int b[])
{
	for(int i=1;i<=t;i++)
	{
		int k = a/pow(2,(t-i)*w);
		if(k==0)
		{
			b[i]=0;
			continue;
		}
		else
		{
			b[i]=k;
			a-=k*pow(2,(t-i)*w);
		}
	}
	
}

int modulo(int a,int w)
{
	int k=0;
	k = a/w;
	if(a>=0)
	{
		if(k==0)
		{
			return a;
		}	
		else
		{
			return a-(k*w);
		}	
	}
	else
	{
		while(a<0)
		{
			a=a+w;
		}
		return a;
	}
}


void thuatToanTru(long long int a,long long int b,int t,int w)
{
	int c[100],d[100],arr[100];
	chuyenSoSangMang(t,w,a,c);
	chuyenSoSangMang(t,w,b,d);
	int f,e;
	f = c[t]-d[t];
	int k = pow(2,w);
	arr[t]= modulo(f,k);
	if(f>=0)
	{
		e=0;
	}
	else
	{
		e=1;
	}
	for(int i=t-1;i>=1;i--)
	{
		int j = c[i]-d[i]-e;
		if(j<0)
		{
			arr[i] = modulo(j,k);
			e=1;
		}
		else
		{
			arr[i] = modulo(j,k);
			e=0;
		}
	}
	cout<<"c=a-b=("<<e<<", [";
	for(int i=1;i<=t;i++)
	{
		if(i==t)
		{
			cout<<arr[i];
			cout<<"])";
			break;
		}
		cout<<arr[i]<<"   ";
	}
}

int main()
{
	long long int a,b,p;
	int w,m,t;
	cin>>p;
	cin>>w; 
	cin>>a;
	cin>>b;
	
	m = log2(p);
	t= (m/w)+1;
	
	thuatToanTru(a,b,t,w);
	
	
}
