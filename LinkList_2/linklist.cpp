#include "linklist.h"
#include<iostream>
using std::cout;
using std::endl;

void Print(const int &n)
{
	cout<<n<<" ";
}

int main()
{
	int p[5]={7,5,1,3,9},a;
	LinkList<int> llist1(p,5),llist2(llist1),llist3;
	
	llist2.Traverse(Print);  //�������
	cout<<endl;	
	
	llist1.Traverse(Print);
	cout<<endl;
	
	llist1.InsertElem(100);  //��ĩβ����
	llist1.Traverse(Print);
	cout<<endl;
	
	llist1.InsertElem(3,90);  //��ָ��λ�ò���
	llist1.Traverse(Print);
	cout<<endl;

	llist1.DeleteElem(2,a);  //ɾ��
	llist1.Traverse(Print);
	cout<<endl;

	cout<<llist1.LocateElem(5)<<endl;  //��λ

	llist1.GetElem(6,a);  //ȡԪ��
	cout<<a<<endl;

	llist1.SetElem(1,80);  //��ֵ
	llist1.Traverse(Print);
	cout<<endl;

	llist3=llist1;  //�����ֵ
	llist1.Traverse(Print);
	cout<<endl;
	return 0;
}
