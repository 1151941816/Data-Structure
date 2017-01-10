#ifndef SEQ_QUEUE_H   //ѭ�����У�������������
#define SEQ_QUEUE_H
#include<iostream>
#define DEFAULT_SIZE 10
using std::cout;

template<typename ElemType>
class SeqQueue
{
protected:
	int front,rear;
	int maxSize;
	ElemType *elems;

public:
	SeqQueue(int size=DEFAULT_SIZE);
	virtual ~SeqQueue();
	int EnQueue(const ElemType &e);  //����״̬
	int DelQueue(ElemType &e);  //����״̬
	int GetLength();   //���ظ���
	void Traverse();
};

template<typename ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
{
	maxSize=size;
	front=rear=0;
	elems=new ElemType[maxSize];
}
template<typename ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
	if(elems!=NULL)
		delete[] elems;
}

template<typename ElemType>
int SeqQueue<ElemType>::EnQueue(const ElemType &e)
{
	if(rear-front==maxSize)   //��������
		return 0;
	elems[rear%maxSize]=e;
	rear++;
	return 1;
}

template<typename ElemType>
int SeqQueue<ElemType>::DelQueue(ElemType &e)
{
	if(rear==front)   //����Ϊ��
		return 0;
	e=elems[front%maxSize];
	front++;
	return 1;
}

template<typename ElemType>
int SeqQueue<ElemType>::GetLength()
{
	return rear-front;
}

template<typename ElemType>
void SeqQueue<ElemType>::Traverse()
{
	int length=rear-front;    //���Խ�һ���Ľ�Ϊ��Ҫrear��ֻҪlength���ݳ�Ա�������ϸ���
	int i,j;
	for(i=front%4,j=0;i<maxSize&&j<length;i++,j++)
		cout<<elems[i]<<" ";
	if(i==maxSize)
	{
		for(i=0;j<length;j++)
			cout<<elems[i]<<" ";
	}
}
#endif