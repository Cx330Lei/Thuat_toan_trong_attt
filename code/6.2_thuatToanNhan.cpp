#include <iostream>
#include <math.h>

using namespace std;

void thuatToanNhan(int c[],int d[],int t,int w)
{
	int arr[t+1],e,u,v;

	for(int i=0;i<t;i++)
	{
		arr[i]=0;
	}
	for(int i=0;i<t;i++)
	{
		u=0;
		for(int j=0;j<t;j++)
		{
			e=arr[i+j]+c[i]*d[j]+u;
			v=0;
			for(int k=0;k<8;k++)
			{
				v+=(e%2)*pow(2,k);
				e = e/2;
			}
			u=e;
			arr[i+j]=v;	
		}
		arr[i+t] =u;	
	}
	cout<<"c=a.b=[";
	for(int i=7;i>=0;i--)
	{
		if(i==0){
			cout<<arr[i]<<"]";
			break;
		}
		cout<<arr[i]<<"   ";
	}
}


int main()
{
	int w,m,t,a,b;
	long long int p;
	cin>>p;
	cin>>w;
	m = log2(p);
	t= (m/w)+1;
	int c[t+1],d[t+1];
	for(int i=(t-1);i>=0;i--)
	{
		cin>>a;
		c[i]=a;
	}

	for(int i=(t-1);i>=0;i--)
	{
		cin>>b;
		d[i] = b;
	}
	thuatToanNhan(c,d,t,w);
	
}
