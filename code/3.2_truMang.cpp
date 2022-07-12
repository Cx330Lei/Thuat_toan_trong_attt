#include <iostream>
#include <math.h>

using namespace std;

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

void thuatToanTru(int a[],int n,int b[],int arr[],int w)
{
	int f,e;
	f = a[n]-b[n];
	int k = pow(2,w);
	arr[n]= modulo(f,k);
	if(f>=0)
	{
		e=0;
	}
	else
	{
		e=1;
	}
	for(int i=3;i>=1;i--)
	{
		int j = a[i]-b[i]-e;
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
	cout<<"c=a-b=("<<e<<",[";
	for(int i=1;i<=n;i++)
	{
		if(i==n)
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
	int c,d,t,w,m;
	long p;
	int a[100];
	int b[100];
	int arr[100];
	cout<<"Nhap so p= ";
	cin>>p;
	cout<<"Nhap so w= ";
	cin>>w;
	m = log2(p);
	t= (m/w)+1;
	cout<<"Nhap mang a :";
	for(int i=1;i<=t;i++)
	{
		cin>>c;
		a[i]=c;
	}
	cout<<"Nhap so b: ";
	for(int i=1;i<=t;i++)
	{
		cin>>d;
		b[i]=d;
	}
	thuatToanTru(a,t,b,arr,w);
}
