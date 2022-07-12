#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long int a,b,c,n,m;
	long long int d,x,y,x1,x2,y1,y2,q,r;
	cin>>a;
	cin>>b;
	n=a;
	m=b;
	if(a<b)          // ddieeeu kiên a phai lon hon b
	{
		c=b;
		b=a;
		a=c;
	}	
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
		if(n<m)
		{
			while(x<0)
			{
				x+=n;
			}
			cout<<"x = "<<y<<", y = "<<x<<"\n";
			cout<<m<<"^-1 mod "<<n<<" = "<<x<<"d ="<<d;
		}
		else
		{
			while(y<0)
			{
				y+=n;
			}
			cout<<"x = "<<x<<", y = "<<y<<"\n";
			cout<<m<<"^-1 mod "<<n<<" = "<<y<<"d ="<<d;
		}
	}
	else
	{
		x2=1;
		x1=0;
		y2=0;
		y1=1;
		while(b>0)
		{
			q=a/b;
			r=a-(q*b);
			x=x2-(q*x1);
			y=y2-(q*y1);
			a=b;
			b=r;
			x2=x1;
			x1=x;
			y2=y1;
			y1=y;
			//cout<<"x = "<<x<<", y= "<<y<<",a "<<a<<"b "<<b<<", x2 = "<<x2<<", X1  = "<<x1<<", y2= "<<y2<<", y1= "<<y1<<endl;
		}
		d=a;
		x=x2;
		y=y2;
		if(n<m)
		{
			while(x<0)
			{
				x+=n;
			}
			cout<<"x = "<<y<<", y = "<<x<<"\n";
			cout<<m<<"^-1 mod "<<n<<" = "<<x<< " , d = "<<d;
		}
		else
		{
			while(y<0)
			{
				y+=n;
			}
			cout<<"x = "<<x<<", y = "<<y<<"\n";
			cout<<m<<"^-1 mod "<<n<<" = "<<y<< " , d = "<<d;
		}
	}
}

