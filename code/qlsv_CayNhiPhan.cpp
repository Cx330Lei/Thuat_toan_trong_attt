#include<iostream>
#include<stdlib.h>
#include<cstdio>

using namespace std;
struct student
{
	int studID;
	char name[30];
	char date[20];
	char gender[5];
	char nameClass[10];
	char address[50];
};
struct node
{
	student data;
	node *left, *right;
};

typedef struct node* Tree;

student inputStud()
{
	student x;
	cout<<"\nNhap ma so sinh vien: ";
	cin>>x.studID;
	cout<<"Nhap ten sinh vien: ";
	fflush(stdin);
	gets(x.name);
	cout<<"Nhap ngay sinh cua sinh vien: ";
	gets(x.date);
	cout<<"Nhap gioi tinh cua sinh vien: ";
	gets(x.gender);
	cout<<"Nhap lop cua sinh vien: ";
	gets(x.nameClass);
	cout<<"Nhap dia chi cua sinh vien: ";
	gets(x.address);
	return x;
}

int addStudent(Tree &T,student x)
{
	if(T != NULL)
	{
		if(x.studID == T->data.studID)
			return -1;
		else if(x.studID > T->data.studID)
			return addStudent(T->right,x);
		else
			return addStudent(T->left,x);
	}
	T = (node *)malloc(sizeof(node));
	if (T == NULL)
		return 0; 
	T->data = x;
	T->left = T->right = NULL;
	return 1;
}
void createTree(Tree &T)
{
	student x;
	while(1)
	{
		cout<<"Nhap thong tin sinh vien can them ";
		x = inputStud();
		int check = addStudent(T,x);
		if(check == -1)
			cout<<"\nMa sinh vien nay da ton tai vui long nhap ma khac";
		else if(check == 0)
			cout<<"\nBo nho day";
		else
			cout<<"\nThem thanh cong!";
		cout<<"\nNhan 1 de dung them,Nhan so bat ki de tiep tuc ";
		int k;
		cin>>k;
		if(k==1)
			break;
	}
}	
void outputSt(student x)
{
	cout<<"\n__________________________________________________";
	cout<<"\nMa so: "<<x.studID;
	cout<<"\nTen: "<<x.name;
	cout<<"\nNgay sinh: "<<x.date;
	cout<<"\nGioi tinh: "<<x.gender;
	cout<<"\nLop: "<<x.nameClass;
	cout<<"\nDiaChi: "<<x.address;
}

void LNR(Tree T)
{
	if(T != NULL)
	{
		LNR(T->left);
		outputSt(T->data);
		LNR(T->right);
	}
}
void searchSt(Tree T,student x)
{
	if(T == NULL)         
	{
		return;
	}
	else
	{
		if(T->data.studID == x.studID)
			outputSt(T->data);
		else if(x.studID > T->data.studID)
			searchSt(T->right,x);
		else
			searchSt(T->left,x);
	}
}

void BTS_Delete(Tree &T,int x)
{
	node* P = T; 
	node* Q = NULL;
	while(P!=NULL)
	{
		if(P->data.studID == x)
			break;
		Q = P;
		if( x <P->data.studID)
			P = P->left;
		else
			P = P->right;
	}
	if(P == NULL)
		return;
	if(P->right!=NULL && P->left!=NULL)
	{
		node* n = P;              // ghi nho nut can xoa
		Q = P; P= P->right;    //chuyen sang nhanh phai dde tim nut trai nhat
		while( P->left!=NULL)
		{
			Q = P; P = P->left;
		}
		n->data = P->data;
	}
	node* child = NULL;
	if(P->left!=NULL)
		child = P->left;
	else
		child = P->right;
	if(P==T)
		T = child;
	else
	{
		if(Q->left == P)
			Q->left = child;
		else
			Q->right = child;
	}
	delete P;
}
void menu()
{
	Tree T = NULL;
	while(1)
	{
		
		cout<<"\n\t\t1. Them sinh vien vao danh sach";
		cout<<"\n\t\t2. In tat ca sinh vien ra man hinh";
		cout<<"\n\t\t3. Tim kiem sinh vien theo ma so";
		cout<<"\n\t\t4. Xoa sinh vien khoi danh sach";
		cout<<"\n\t\t\t__________________________________________________";
		cout<<"\nNhap lua chon cua ban ";
		
		int choose;
		cin>> choose;
		switch(choose)
		{
			case 1:
				createTree(T);
				break;
			case 2:
				LNR(T);
				break;
			case 3:
				cout<<"\nNhap ma so sinh vien can tim: ";
				int n;
				cin>>n;
				student x;
				x.studID = n;
				searchSt(T,x);
				break;
			case 4:
				cout<<"\nNhap ma so sinh vien can xoa: ";
				int a;
				cin>>a;
				BTS_Delete(T,a);
				cout<<"\nXoa Thanh Cong!";
				break;
		}
	}
}
int main()
{
	menu();
}
