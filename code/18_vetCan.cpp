#include <iostream>
#include <string>

using namespace std;

void vetCan(string t,string p)
{
	int m,n,dem=0;
	m = t.length();
	n = p.length();
	for(int i=0;i<m;i++)
	{
		int j=0;
		while((j<n)&&(t[i+j]==p[j]))
		{
			j++;
			dem++;
		}
		if(j==n)
		{
			cout<<"Su xuat hien cua mau \""<<p<<"\" trong van ban \""<<t<<"\" co vi tri bat dau la "<<i<<", so phep lap la "<<dem;
			break;
		}
		dem++;
		if(i==(m-n))
		{
			cout<<"Mau \""<<p<<"\" khong xuat hien trong van ban \""<<t<<"\", so phep lap la "<<dem;
			break;
		}
	}
}
int main()
{
	string t;
	string p;
	cout<<"Nhap mau can tim P:";
	getline(cin, p);
	fflush(stdin);
	cout<<"Nhap van ban T:";
	getline(cin, t);
	vetCan(t,p);
}
