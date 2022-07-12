#include <iostream>
#include <math.h>
#include <iomanip>
#include<stdlib.h>

using namespace std;

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
 void pollardRho(long long int n)
 {
 	long long int a,b,d;
	int w=20;
	a=2,b=2;
	for(int i = 0 ; i < 64; i++)
    {
        cout<<"-";
    }
	cout<<"\n|"<<setw(w)<<"a"<<"|"<<setw(w)<<"b"<<"|"<<setw(w)<<"d"<<"|"<<endl;
	while(1)
	{
		a=(a*a+1)%n;
        b=(b*b+1)%n;
        b=(b*b+1)%n;
		d = gcd(abs(a-b),n);
		for(int i = 0 ; i < 64; i++)
        {
            cout<<"-";
        }
		cout<<"\n|"<<setw(w)<<a<<"|"<<setw(w)<<b<<"|"<<setw(w)<<d<<"|\n";
		
		if(d>1&&d<n)
		{
			for(int i = 0 ; i < 64; i++)
        	{
           		cout<<"-";
       		}
			cout<<"\nThua so khong tam thuong cua "<<n<<" la "<<d;
			break;
		}
		if(d==n)
		{
			for(int i = 0 ; i < 64; i++)
        	{
           	 	cout<<"-";
       		}
			cout<<"\nKhong tim thay";
			break;
		}
	}
 }
int main()
{
	long long int n;
	cin>>n;
	pollardRho(n);
}
