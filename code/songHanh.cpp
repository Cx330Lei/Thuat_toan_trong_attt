#include <iostream>
#include <math.h>
#include <string>
using namespace std;

string phanTichNguyenTo(int n)
{

    string s ="";
    for(int i=2; i<=n; i++)
	{
        if(n%i==0)
        {
    		while(n%i==0)
			{
            	n /= i;
        	}
        	s += i;
		}
    }
	return s;
}
int kiemTraSongHanh(int a,int b)
{
	if(phanTichNguyenTo(a)==phanTichNguyenTo(b))
		return 1;
	return 0;
}

int kiemTraDoan(int n,int m)
{
	int dem=0;
	for(int i=n; i<m; i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(kiemTraSongHanh(i,j)==1)
				dem++;
		}
	}
	return dem;
}
int main()
{
    int T,x,y;
    cin>>T;
    int S[T];
    for(int i=1; i<=T; i++)
    {
    	cin>>x>>y;
    	S[i] = kiemTraDoan(x,y);
	}
	for(int i=1; i<=T; i++)
    {
    	cout<<S[i]<<endl;
	}
}
 
