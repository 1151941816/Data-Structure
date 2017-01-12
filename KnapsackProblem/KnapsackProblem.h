#ifndef KNAPSPACK_PROBLEM_H
#define KNAPSPACK_PROBLEM_H
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

void KnapspackProblem(int n,int *weight,int *value,int capacity)  //���빲������Ʒ�����ǵ���������ֵ���Լ�����������
{
	int **p=new int*[n],i,j;
	for(i=0;i<n;i++)
        p[i]=new int[capacity+1];
	for(i=0;i<weight[0];i++)   //�������һ��
		p[0][i]=0;
	for(i=weight[0];i<capacity+1;i++)   //�������һ��
		p[0][i]=value[0];
	for(i=1;i<n;i++)              //�ٴ�����漸��
		for(j=0;j<capacity+1;j++)
		{
			if(j<weight[i])
				p[i][j]=p[i-1][j];
			else
			{
				if((p[i-1][j-weight[i]]+value[i])>p[i-1][j])
					p[i][j]=p[i-1][j-weight[i]]+value[i];
				else
					p[i][j]=p[i-1][j];
			}
		}
		cout<<"���������ֵΪ:"<<p[n-1][capacity]<<endl;   //���㷨��ʱ�临�Ӷ�ΪO(n*capacity)
		for(i=0;i<n;i++)
			delete[] p[i];
		delete[] p;
}

#endif