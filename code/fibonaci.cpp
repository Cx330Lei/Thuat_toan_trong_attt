#include <iostream>

using namespace std;
int fibonaci(int n)
{
	if(n == 1 || n == 2)
    	return 1;
    return fibonaci(n-1) + fibonaci(n-2);
}
int main()
{
	int n,m,arr[10];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		arr[i] = fibonaci(m);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	
}
