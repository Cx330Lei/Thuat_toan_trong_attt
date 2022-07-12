#include <iostream>
#include <math.h>

using namespace std;

void chuyenSoSangMang(int t,int w,double a,int b[])
{
	int k;
	for(int i=1;i<=t;i++)
	{
		k=a/(pow(2,(t-i)*w));
		if(k==0)
		{
			b[i] =0;
			continue;
		}
		else
		{
			b[i]=k;
			a=a-k*(pow(2,(t-i)*w));
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

int thuatToanTru(int c[],int d[],int t,int w)
{
	int arr[100];
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
	cout<<"[";
	for(int i=1;i<=t;i++)
	{
		if(i==t)
		{
			cout<<arr[i];
			cout<<"]";
			break;
		}
		cout<<arr[i]<<"   ";
	}
}

int soSanhMang(int a[],int b[],int n)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		{
			return 1;
			break;
		}
		else if(a[i]==b[i])
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
}

int thuatToanCongTrenFp(int c[],int d[],double p,int t,int w) // n la so luong phan tu trong mang
{
	int arr[100],arrp[100];
	int f,e;
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
	
	chuyenSoSangMang(t,w,p,arrp);
	if(e==1)
	{ 
		thuatToanTru(arr,arrp,t,w);
	}
	else
	{
		if(soSanhMang(arr,arrp,t)==1)
		{
			thuatToanTru(arr,arrp,t,w);
		}
		else
		{
			cout<<"[";
			for(int i=1;i<=t;i++)
			{
				if(i==t)
				{
					cout<<arr[i];
					cout<<"]";
					break;
				}
				cout<<arr[i]<<"   ";
			}
		}
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

	thuatToanCongTrenFp(a,b,p,t,w);
}
