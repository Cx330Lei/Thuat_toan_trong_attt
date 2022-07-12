#include <iostream>
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
int main()
{
	long long int a,k,n;
	cin>>a;
	cin>>k;
	cin>>n;
	cout<<"ket qua "<<thuatToanBinhPhuongCoLap(a,k,n);
	
}
