#include <iostream>

using namespace std;
void phanTichNguyenTo (int n)
{

    int dem,k=0;
    for (int i=2; i<=n; i++)
	{
        dem = 0;
        if(n%i==0)
        {
    		while(n%i==0)
			{
           		dem++;
            	n /= i;
        	}
        	if(k==0)
        	{
        		cout<<i<<"^"<<dem;	
			}
			else
			{
				cout<<" + "<<i<<"^"<<dem;
			}
        	k++;	
		}
    }
	
}
int main()
{
	int n;
	cin>>n;
	phanTichNguyenTo(n);
}
