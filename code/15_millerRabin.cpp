#include <iostream>
#include <math.h>

using namespace std;
int thuatToanBinhPhuongCoLap(long long int a,long long int b,long long int n)
{
	long long int A,B[100],t=0,e,f,c;
	c=b;
	while(b>0)
	{
		B[t] = b%2;
		b = b/2;
		t++;
	} 
	b=1;
	A=a;
	if(B[0]==1)
	{
		b=a;
	}
	for(int i=1;i<t;i++)
	{
		f=A*A;
		A=f%n;
		if(B[i]==1)
		{
			e = A*b;
			b=e%n;
		}
	}
	return b;
}
int millerRanbin(long long int n,long long int a,long long int b)
{
	int t,s,dem =0,y,j,k,h=0,r;						
	k = n-1;
	while((k%2)==0)										
	{
		k = k/2;
		dem++;   
	}
	r = k;
	s = dem;
	cout<<"Kiem tra so nguyen n="<<n<<":"<<endl;
	cout<<n<<"-1 = 2^"<<dem<<"."<<r<<endl;
	for(long long int i=a+1;i<b;i++)
	{
		cout<<"Co so a= "<<i<<":"<<endl;
		y = thuatToanBinhPhuongCoLap(i,r,n);			
		if((y!=1)&&(y!=n-1))
		{
			cout<<"y= "<<y<<" => (y!=1)&&(y!=n-1)"<<endl;
			cout<<"   j=1"<<endl;
			j=1;
			while((j<=s-1)&&(y!=n-1))
			{
				cout<<"   j="<<j<<", y="<<y<<" =>(j<=s-1)&&(y!=n-1)"<<endl;
				y =(y*y)%n;
				if(y==1)
				{
					cout<<"   y="<<y<<endl;
					cout<<"Ket qua: Hop so"<<endl;
					h++;
					break;
				}
				j = j+1;
			}
			if(y==1)
			{
				continue;
			}
			if(y!=n-1)
			{
				cout<<"y = "<<y<<" => y!=n-1"<<endl;
				cout<<"Ket qua: Hop so"<<endl;
				h++;
				continue;
			}
		}
        printf("Ket qua: Nguyen to\n");
	}
	return h;
}
int main()
{
	long long int n,a,b,k;				
	cin>>n;
	cin>>a;
	cin>>b;
	k = millerRanbin(n,a,b);
	if(k>0)
	{
		cout<<n<<" la hop so";
	}
	else
	{
		cout<<n<<" co the la nguyen to";
	}
}
