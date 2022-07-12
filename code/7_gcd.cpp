#include <iostream>
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
 
int main(){
    long a,b;
    int t,c[100];
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>a;
		cin>>b;
		c[i] = gcd(a,b);
	}
   	for(int i=1;i<=t;i++)
   	{
   		if(i==t)
   		{
   			cout<<c[i];
   			break;
		}
   		cout<<c[i]<<"\n";
	}
    return 0;
}
