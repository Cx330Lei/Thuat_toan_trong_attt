#include <iostream>

using namespace std;
int dong[8], cot[8], cheoXuoi[15], cheoNguoc[15];

void hienThi()
{
	int i ;
	for(int i=0; i<8; i++)
		cout<<cot[i]<<"  ";
	cout<<"\n";
}
void tryQueens(int j)    //lua chon hang i cho quan hau j tai cot j
{
	for(int i=0; i < 8; i++)
	{
		if(dong[i]==1 && cheoXuoi[i+j] == 1 && cheoNguoc[i-j+7] == 1)
		{
			cot[j] = i;           //dat hau tai hang i cho cot thu j
			dong[i] = 0;
			cheoXuoi[i+j] = 0;
			cheoNguoc[i-j+7] = 0;
			if( j < 7)
			{
				tryQueens(j+1); 
			}
			else
				hienThi();
			dong[i] = 1;
			cheoXuoi[i+j] = 1;
			cheoNguoc[i-j+7] = 1;
		}
	}
}  
int main()
{
	for(int i=0; i < 8; i++)
	{
		dong[i] = 1;
		cot[i] = 1;
	}
	for(int i =0; i < 15; i++)
	{
		cheoXuoi[i] = 1;
		cheoNguoc[i] = 1;
	}
	tryQueens(0);
}
