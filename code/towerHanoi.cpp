#include <iostream>
using namespace std;

towerHanoi(int n,char A,char B,char C)
{
	if(n == 1)
	{
		cout<<"\nChuyen 1 dia tu " <<A<<" sang "<<C;
	}
	else
	{
		towerHanoi(n-1,A, C, B);
		cout<<"\nChuyen dia "<<n<<" tu " <<A<<" sang "<<C;
		towerHanoi(n-1,B, A, C);
	}
}
int main()
{
	int n;
	char A = 'A';
	char B = 'B';
	char C = 'C';
	cout<<"Nhap so dia muon xep: ";
	cin>>n;
	towerHanoi(n,A,B,C);
}
