#ifndef ADJ_LIST_DIR_GRAPH_VEX_H
#define ADJ_LIST_DIR_GRAPH_VEX_H
#include "AdjListDirGraphArc.h"
#include <iostream>
using namespace std;

//����ͼ�ڽӱ����㶨��
template<typename ElemType>
struct AdjListDirGraphVex   
{
//���ݳ�Ա:
	ElemType data;
	AdjListDirGraphArc *firstArc;

//���캯��:
	AdjListDirGraphVex();   //�޲ι��캯��
	AdjListDirGraphVex(ElemType VexValue,AdjListDirGraphArc *_firstArc=NULL);  //�вι��캯��
};

template<typename ElemType>
AdjListDirGraphVex<ElemType>::AdjListDirGraphVex():firstArc(NULL) 
{
}

template<typename ElemType>
AdjListDirGraphVex<ElemType>::AdjListDirGraphVex(ElemType VexValue,AdjListDirGraphArc *_firstArc)
{
	data=VexValue;
	firstArc=_firstArc;
}
#endif