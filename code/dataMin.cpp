#include <iostream>
#include <string.h>
#include<stdlib.h>
using namespace std;

int main()
{
	char *data;
	data = (char*)malloc(sizeof(char));
	gets(data);
	int l = strlen(data);
	int dem;
	for(int j = 0; j < l; j++)
	{
		dem =1;
		for(int i=j+1; i < l; i++)
		{
			if(*(data+j) == *(data+i))
			{
				int a = i;
				dem++;
				while(a<l)
				{
					*(data+a)=*(data+a+1);
					a++;
				}
				l--;
				i--;
			}
		}
		cout<<*(data+j)<<" "<<dem<<endl;
	} 
}
