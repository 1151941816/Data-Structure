#include "AdjListDirGraph.h"

int main()
{
//�����ʼͼ:
	char vexs[]="ABC";
	AdjListDirGraph<char> graph(vexs,3);
	graph.InsertArc(0,2);
	graph.InsertArc(0,1);
	graph.InsertArc(1,2);
	graph.InsertArc(2,1);

//�Ը�ͼ���в��ֳ��ò���:
	cout<<"1. ��ʾ��ǰ����ͼ"<<endl;
	cout<<"2. ���붥��"<<endl;
	cout<<"3. ���뻡"<<endl;
	cout<<"4. ɾ����"<<endl;
	cout<<"5. ɾ������"<<endl;
	cout<<"6. �����������v�ĵ�һ���ڽӶ���"<<endl;
	cout<<"7. �����������v1����ĳһ������v2����һ�ڽӶ���"<<endl;
	cout<<"0. �˳�"<<endl;
	cout<<"��ѡ����(0~7):";
	char c,e,e1,e2,ee;
	while(cin>>c && c!='0')	
	{
		if(c=='1')
		{
			cout<<"\n1. ��ʾ��ǰ����ͼ"<<endl;
			graph.Display();
			cout<<endl<<"��ѡ����(0~7):";
		}
		else if(c=='2')
		{
			cout<<"\n2. ���붥��"<<endl;
			cout<<"���������Ķ���:";
			cin>>e;
			graph.InsertVex(e);
			cout<<"ִ�����"<<endl<<"\n��ѡ����(0~7):";
		}
		else if(c=='3')
		{
			cout<<"\n3. ���뻡"<<endl;
			cout<<"��������û���������յ�:";
			cin>>e1>>e2;
			graph.InsertArc(graph.GetOrder(e1),graph.GetOrder(e2));
			cout<<"ִ�����"<<endl<<"\n��ѡ����(0~7):";
		}
		else if(c=='4')
		{
			cout<<"\n4. ɾ����"<<endl;
			cout<<"��������û���������յ�:";
			cin>>e1>>e2;
			graph.DeleteArc(graph.GetOrder(e1),graph.GetOrder(e2));
			cout<<"ִ�����"<<endl<<"\n��ѡ����(0~7):";
		}
		else if(c=='5')
		{
			cout<<"\n5. ɾ������"<<endl;
			cout<<"������ɾ���Ķ���:";
			cin>>e;
			graph.DeleteVex(e);
			cout<<"ִ�����"<<endl<<"\n��ѡ����(0~7):";
		}
		else if(c=='6')
		{
			cout<<"\n6. �����������v�ĵ�һ���ڽӶ���"<<endl;
			cout<<"����������Ķ���v:";
			cin>>e;
			ee=graph.GetElem(graph.FirstAdjVex(graph.GetOrder(e)));
			cout<<"�ö���ĵ�һ���ڽӶ���Ϊ:"<<ee<<endl;
			cout<<"ִ�����"<<endl<<"\n��ѡ����(0~7):";
		}
		else if(c=='7')
		{
			cout<<"\n7. �����������v1����ĳһ������v2����һ�ڽӶ���"<<endl;
			cout<<"������v1��v2:";
			cin>>e1>>e2;
			ee=graph.GetElem(graph.NextAdjVex(graph.GetOrder(e1),graph.GetOrder(e2)));
			cout<<"��һ�ڽӶ���Ϊ:"<<ee<<endl;
			cout<<"ִ�����"<<endl<<"\n��ѡ����(0~7):";
		}
	}
	return 0;
}