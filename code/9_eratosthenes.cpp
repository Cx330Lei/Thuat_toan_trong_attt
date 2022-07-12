#include <iostream>

using namespace std;

int main()
{
	long long int n;
	cin>>n;
	bool a[n+1];
	cout<<"Liet ke cac so nguyen tu 2 den "<<n<<endl;
	for(int i=2;i<=n;i++)
	{
		cout<<i<<"  ";
		a[i]= true;
	}
	cout<<endl;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==true)
		{
			cout<<"p="<<i<<endl;
			for(int j=2*i;j<=n;j+=i)
			{
				a[j]= false;
			}
			for(int i=2;i<=n;i++)
			{
				if(a[i]==true)
				{
					cout<<i<<"  ";
				}
			}
			cout<<endl;
		}
	}
	cout<<"Cac so nguyen to <="<<n<<" la:"<<endl;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==true)
		{
			cout<<i<<"  ";
		}
	}
}
