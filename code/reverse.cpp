#include <iostream>

using namespace std;
void reverse(int n)
{
	if(n==0)
		exit(0);
	cout<<n%10;
	reverse(n/10);
}
int main()
{
	int n;
	cin>>n;
	reverse(n);
}
