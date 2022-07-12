#include <iostream>
#include <math.h>

using namespace std;

void chuyenSoSangMang(int t,int w,double a,int b[])
{
	int k;
	cout<<"A= [";
	for(int i=1;i<=t;i++)
	{
		k=a/(pow(2,(t-i)*w));
		if(k==0)
		{
			b[i] =0;
			if(i==t){
				cout<<b[i];
				cout<<"]";
				break;
			}
			cout<<b[i]<<"   ";
			continue;
		}
		else
		{
			b[i]=k;
			if(i==t){
				cout<<b[i];
				cout<<"]";
				break;
			}
			cout<<b[i]<<"   ";
			a=a-k*(pow(2,(t-i)*w));
		}
		
	}
}

int main ()
{
	double a,p;//a la so can chuyen,t so phan tu cua mang(bac)
	int t,w,m;
	int b[100];
	cin>>p;
	cin>>w;
	cin>>a;
	m = log2(p);
	t= (m/w)+1;
	
	chuyenSoSangMang(t,w,a,b);
	
}
