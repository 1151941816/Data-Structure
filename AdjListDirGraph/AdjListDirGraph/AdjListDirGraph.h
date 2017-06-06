#ifndef ADJLIST_UNDIR_GRAPH_H    //�ڽӱ�ʵ������ͼ
#define ADJLIST_UNDIR_GRAPH_H
#include "AdjListDirGraphArc.h"
#include "AdjListDirGraphVex.h"
#include <iostream>
using namespace std;
#define DEFAULT_SIZE 10

enum VisitStatus{VISIT,UNVISIT};

//����ͼ�ڽӱ��ඨ��
template<typename ElemType>
class AdjListDirGraph     
{
public:
	//������Ա:
    AdjListDirGraph(int _vexMaxNum=DEFAULT_SIZE);   //�޲ι��캯��
	AdjListDirGraph(ElemType *Vexs,int _vexNum,int _vexMaxNum=DEFAULT_SIZE);   //�вι��캯��
	~AdjListDirGraph();   //��������
	void Clear();   //������л�
	bool isEmpty();   //�ж�����ͼ�Ƿ�Ϊ��
	ElemType GetElem(int vex);    //��ȡ����Ԫ��ֵ
	int GetOrder(ElemType &e);    //��ȡ��������
	void InsertArc(int vex1,int vex2);     //���뻡
	void InsertVex(ElemType &e);     //���붥��
	void DeleteArc(int vex1,int vex2);     //ɾ����
	void DeleteVex(ElemType &e);     //ɾ������
	int GetVexNum();     //��ȡ����ͼ�Ķ������
	int GetArcNum();     //��ȡ����ͼ�Ļ�������
	int FirstAdjVex(int vex);     //��ȡ����ͼ�ж���vex�ĵ�һ���ڽӵ�
	int NextAdjVex(int vex1,int vex2);     //��ȡ����ͼ�ж���vex1�������vex2����һ���ڽӵ�
	void Display();     //��ʾ����ͼ

private:
	//���ݳ�Ա:
	VisitStatus *tag;
	AdjListDirGraphVex<ElemType> *vexTable;
	int vexNum;
	int vexMaxNum;
	int arcNum;

};

template<typename ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(int _vexMaxNum)
{
	vexMaxNum=_vexMaxNum;
	vexNum=0;
	arcNum=0;
	tag=new VisitStatus[vexMaxNum];
	vexTable=new AdjListDirGraphVex<ElemType>[vexMaxNum];
}

template<typename ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(ElemType *Vexs,int _vexNum,int _vexMaxNum)
{
	vexMaxNum=_vexMaxNum;
	vexNum=_vexNum;
	arcNum=0;
	tag=new VisitStatus[vexMaxNum];
	vexTable=new AdjListDirGraphVex<ElemType>[vexMaxNum];
	for(int i=0;i<vexNum;i++)
	{
		tag[i]=UNVISIT;
		vexTable[i].data=Vexs[i];
	}
}

template<typename ElemType>
AdjListDirGraph<ElemType>::~AdjListDirGraph()
{
	if(tag!=NULL)
		delete[] tag;
	Clear();
	if(vexTable!=NULL)
		delete[] vexTable;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::Clear()
{
	AdjListDirGraphArc *p;
	for(int i=0;i<vexNum;i++)
		while(vexTable[i].firstArc!=NULL)
		{
			p=vexTable[i].firstArc;
			vexTable[i].firstArc=p->nextArc;
			delete p;
		}
	arcNum=0;
}

template<typename ElemType>
bool AdjListDirGraph<ElemType>::isEmpty()
{
	return vexNum==0;
}

template<typename ElemType>
ElemType AdjListDirGraph<ElemType>::GetElem(int vex)
{
	return vexTable[vex].data;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::GetOrder(ElemType &e)
{
	for(int i=0;i<vexNum;i++)
		if(vexTable[i].data==e)
			return i;
	return -1;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::InsertArc(int vex1,int vex2)
{
	if(vex1<0 || vex1>=vexNum)
		cout<<"vex1���Ϸ�!";	 
	else if(vex2<0 || vex2>=vexNum)
		cout<<"vex2���Ϸ�!";	 
	else if(vex1==vex2)
		cout<<"vex1���ܵ���vex2!";  
	else
	{
	    vexTable[vex1].firstArc=new AdjListDirGraphArc(vex2,vexTable[vex1].firstArc);
		arcNum++;
	}

}
template<typename ElemType>
void AdjListDirGraph<ElemType>::InsertVex(ElemType &e)
{
	if(vexNum==vexMaxNum)
		cout<<"ͼ�Ķ��������ܳ�������������!"<<endl;
	vexTable[vexNum].data=e;
	vexTable[vexNum].firstArc=NULL;
	tag[vexNum]=UNVISIT;
	vexNum++;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::DeleteArc(int vex1,int vex2)
{
	if(vex1<0 || vex1>=vexNum)
		cout<<"vex1���Ϸ�!";	 
	if(vex2<0 || vex2>=vexNum)
		cout<<"vex2���Ϸ�!";	
    AdjListDirGraphArc *p=vexTable[vex1].firstArc,*q;
	while(p!=NULL && p->adjVex!=vex2)
	{
		q=p;
		p=p->nextArc;
	}
	if(p!=NULL)
	{
		if(vexTable[vex1].firstArc==p)
			vexTable[vex1].firstArc=p->nextArc;
		else
			q->nextArc=p->nextArc;
		delete p;
		arcNum--;
	}
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::DeleteVex(ElemType &e)
{
	int v=GetOrder(e),u;
	if(v==-1)
		cout<<"ͼ�в�����Ҫɾ���Ķ���!"<<endl;
	else
	{
		for(u=0;u<vexNum;u++)
			if(u!=v)
				DeleteArc(u,v);
		 AdjListDirGraphArc *p=vexTable[v].firstArc;
		 while(p!=NULL)
		 {
			 vexTable[v].firstArc=p->nextArc;
			 delete p;
			 p=vexTable[v].firstArc;
			 arcNum--;
		 }
		 if(v==vexNum-1)
			 vexNum--;
		 else
		 {
			 vexNum--;
			 vexTable[v]=vexTable[vexNum];
			 vexTable[vexNum].firstArc=NULL;
			 tag[v]=tag[vexNum];
			 for(u=0;u<vexNum;u++)
				 if(u!=v)
				 {
					 p=vexTable[u].firstArc;
					 while(p!=NULL)
					 {
						 if(p->adjVex==vexNum)
							 p->adjVex=v;
						 p=p->nextArc;
					 }
				 }
		 }
		
	}
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::GetVexNum()
{
	return vexNum;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::GetArcNum()
{
	return arcNum;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::FirstAdjVex(int vex)
{
	if(vex<0 || vex>=vexNum)
		cout<<"vex���Ϸ�!";	 
	if(vexTable[vex].firstArc==NULL)
		return -1;
	else
		return vexTable[vex].firstArc->adjVex;
}

template<typename ElemType>
int AdjListDirGraph<ElemType>::NextAdjVex(int vex1,int vex2)
{
	if(vex1<0 || vex1>=vexNum)
		cout<<"vex1���Ϸ�!";	 
	if(vex2<0 || vex2>=vexNum)
		cout<<"vex2���Ϸ�!";	 
	AdjListDirGraphArc *p=vexTable[vex1].firstArc;
	while(p!=NULL && p->adjVex!=vex2)
		p=p->nextArc;
	if(p==NULL||p->nextArc==NULL)
		return -1;
	else
		return p->nextArc->adjVex;
}

template<typename ElemType>
void AdjListDirGraph<ElemType>::Display()
{
	cout<<"������ͼ��"<<vexNum<<"������,"<<arcNum<<"����"<<endl;
	for(int i=0;i<vexNum;i++)
	{
		cout<<vexTable[i].data<<"���ڽӶ���Ϊ: ";
		AdjListDirGraphArc *p=vexTable[i].firstArc;
		if(p==NULL)
			cout<<"��"<<endl;
		else
		{
			while(p!=NULL)
			{
				cout<<GetElem(p->adjVex)<<" ";
				p=p->nextArc;
			}
			cout<<endl;
		}

	}
}

#endif