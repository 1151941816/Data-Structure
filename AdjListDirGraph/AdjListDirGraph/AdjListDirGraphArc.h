#ifndef ADJ_LIST_DIR_GRAPH_ARC_H
#define ADJ_LIST_DIR_GRAPH_ARC_H
#include <iostream>
using namespace std;

//����ͼ�ڽӱ�߽�㶨��
struct AdjListDirGraphArc    
{
//���ݳ�Ա:
	int adjVex;
	AdjListDirGraphArc *nextArc;

//���캯��:
	AdjListDirGraphArc();   //�޲ι��캯��
	AdjListDirGraphArc(int _adjVex,AdjListDirGraphArc *_nextArc=NULL);   //�вι��캯��
};

AdjListDirGraphArc::AdjListDirGraphArc():adjVex(-1),nextArc(NULL) 
{
}

AdjListDirGraphArc::AdjListDirGraphArc(int _adjVex,AdjListDirGraphArc *_nextArc)
{
	adjVex=_adjVex;
	nextArc=_nextArc;
}
#endif