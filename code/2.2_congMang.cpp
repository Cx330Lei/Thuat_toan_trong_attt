//Nhap lan luot p,w,mang a,mang b
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

void thuatToanCong(int c[],int d[],int t,int w) 
{
	int f,e,arr[100];
	f = c[t]+d[t];
	int k = pow(2,w);
	arr[t]= modulo(f,k);
	if(arr[t]==f)
	{
		e=0;
	}
	else
	{
		e=1;
	}
	
	for(int i=t-1;i>=1;i--)
	{
		int j = c[i]+d[i]+e;
		if(j>=k)
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
	
	cout<<"A+B=("<<e<<", [";
	cout<<arr[1];
	cout<<"    ";
	for(int i=2;i<=t;i++)
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
	double p;
	int w,m,t,c,d;
	int a[100];
	int b[100];
	cin>>p;
	cin>>w;
	m = log2(p);
	t= (m/w)+1;
	for(int i=1;i<=t;i++)
	{
		cin>>c;
		a[i]=c;
	}
	
	for(int i=1;i<=t;i++)
	{
		cin>>d;
		b[i]=d;
	}

	thuatToanCong(a,b,t,w);
}
