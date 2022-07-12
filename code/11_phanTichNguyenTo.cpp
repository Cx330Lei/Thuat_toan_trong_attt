#include <iostream>
#include <math.h>

using namespace std;

void phanTichNguyenTo (long int n)
{

    int dem,k=0;
    int a[1000],b[1000];// a la mang chua co so, b la mang chua so mu
    
    for (int i=2; i<=n; i++)
	{
        dem = 0;
        if(n%i ==0)
        {
    		while(n%i==0)
			{
           		dem++;
            	n /= i;
        	}
        	a[k] = i;
       	 	b[k] = dem;
        	k++;
   		}	
    }
	cout<<"coso = [";
    for (int j=0; j<=k; j++)
    {
    	if(j==(k-1))
    	{
    		cout<<a[j]<<"]";
    		break;
		}
    	cout<<a[j]<<",";
	}
    
    cout<<"\nsomu = [";
    for (int j=0; j<=k; j++)
    {
    	if(j==(k-1))
    	{
    		cout<<b[j]<<"]";
    		break;
		}
    	cout<<b[j]<<",";
	}
}
int main()
{
    long int n;
    cout<<"n=";
    cin>>n;
    phanTichNguyenTo(n);
    return 0;
}
