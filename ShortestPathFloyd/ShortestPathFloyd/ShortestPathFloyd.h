#include "AdjMatrixDirNetwork.h"

void ShortestPathFloyd(AdjMatrixDirNetwork &network)   //��Դ�����·��
{
	int **path,**dist,vexNum=network.GetVexNum(),i,j,k;
	path=new int*[vexNum];
	dist=new int*[vexNum];
	for(i=0;i<vexNum;i++)
	{
		path[i]=new int[vexNum];
		dist[i]=new int[vexNum];
	}
	for(i=0;i<vexNum;i++)
		for(j=0;j<vexNum;j++)
		{
			dist[i][j]=(i!=j)?network.GetWeight(i,j):0;
			if(i!=j&&dist[i][j]!=network.GetInfinity())
				path[i][j]=i;
			else
				path[i][j]=-1;
		}
	for(k=0;k<vexNum;k++)
		for(i=0;i<vexNum;i++)
			for(j=0;j<vexNum;j++)
			{
				if(i!=k&&j!=k&&i!=j)
				{
					if(dist[i][k]+dist[k][j]<dist[i][j])
					{
						dist[i][j]=dist[i][k]+dist[k][j];
						path[i][j]=path[k][j];
					}
					   
				}
			}
	for(i=0;i<vexNum;i++)
	{
		cout<<"[ ";
		for(j=0;j<vexNum;j++)
			cout<<dist[i][j]<<" ";
		cout<<"]"<<endl;
	}
	cout<<endl;
	for(i=0;i<vexNum;i++)
	{
		cout<<"[ ";
		for(j=0;j<vexNum;j++)
			cout<<path[i][j]<<" ";
		cout<<"]"<<endl;
	}
	for(i=0;i<vexNum;i++)
		for(j=0;j<vexNum;j++)
		{
			if(i!=j)
			{
				if(path[i][j]!=-1)
				{
					cout<<"�����"<<network.GetElem(i)<<"���յ�"<<network.GetElem(j)<<"�����·������Ϊ:"<<dist[i][j];
					cout<<"  ���·��Ϊ:"<<network.GetElem(j);
					int temp=j;
					while(path[i][temp]!=-1)
					{
						temp=path[i][temp];
						cout<<"<-"<<network.GetElem(temp);
					}
					cout<<endl;
				}
				else
					cout<<"��"<<network.GetElem(i)<<"�޷������"<<network.GetElem(j)<<endl;
			}
		}
	for(i=0;i<vexNum;i++)
	{
		delete[] path[i];
		delete[] dist[i];
	}
	delete[] path;
	delete[] dist;
}