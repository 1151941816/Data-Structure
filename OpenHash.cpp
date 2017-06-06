#include <iostream>
using namespace std;
#define DEFAULT_DIVISOR 11

//����ַ����㶨��
struct HashNode    
{
	int key;
	HashNode *next;

	HashNode();
	HashNode(int _key,HashNode *_next=NULL);
};

HashNode::HashNode()
{
	next=NULL;
}

HashNode::HashNode(int _key,HashNode *_next)
{
	key=_key;
	next=_next;
}

//����ַ��ɢ�б��ඨ��
class OpenHashTable
{
public:
	OpenHashTable(int divisor=DEFAULT_DIVISOR);
	~OpenHashTable();
	HashNode * Find(int key);
	void Insert(int key);
	void Display();

private:
	HashNode *ht;
	int div;    //�����������ĳ���

	int H(int key);
};

int OpenHashTable::H(int key)
{
	return key%div;
}

OpenHashTable::OpenHashTable(int divisor)
{
	div=divisor;
	ht=new HashNode[divisor];
}

OpenHashTable::~OpenHashTable()
{
	for(int i=0;i<div;i++)
	{
		HashNode *p=ht[i].next;
        while(p!=NULL)
		{
			ht[i].next=p->next;
			delete p;
			p=ht[i].next;
		}	
	}
	delete[] ht;
		
}

HashNode * OpenHashTable::Find(int key)
{
	int i=H(key);
	HashNode *p=ht[i].next;
	while(p!=NULL && p->key!=key)
		p=p->next;
	return p;
}

void OpenHashTable::Insert(int key)
{
	int i=H(key);
	HashNode *p=Find(key);
	if(p==NULL)    //�ؼ���δ�ҵ������Բ���
		ht[i].next=new HashNode(key,ht[i].next);   //�ڱ�ͷ����
	else
	    cout<<"�ü�ֵ�Ѵ���"<<endl;
}

void OpenHashTable::Display()
{
	for(int i=0;i<div;i++)
	{
		cout<<i<<": ";
		HashNode *p=ht[i].next;
		while(p!=NULL)
		{
			cout<<p->key<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}

int main()
{
	int a[]={32,40,36,53,16,46,71,27,42,24,49,64},i;
	OpenHashTable htable(13);
	for(i=0;i<12;i++)
		htable.Insert(a[i]);
	htable.Display();
	if(htable.Find(27)!=NULL)
		cout<<"����27�ɹ�!"<<endl;
	return 0;
}
