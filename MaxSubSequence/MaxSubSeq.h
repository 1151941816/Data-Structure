#ifndef MAX_SUB_SEQ     //������к�����
#define MAX_SUB_SEQ
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

void MaxSubSeq_1(int n,int *Seq)   //��һ��������������еĺͣ��ҳ����ֵ������⣬���㷨ʱ�临�Ӷ�ΪO(n^2)
{
	int i,j,MaxSum=0,sum=0;
	for(i=0;i<n;i++)     //�ж��Ƿ�Ϊȫ��
       if(Seq[i]>=0)   
			break;
	if(i==n)   //�ϸ�ѭ�������˳�����������Ϊȫ�������
	{
		MaxSum=Seq[0];
		for(i=1;i<n;i++)
            if(Seq[i]>MaxSum)
				MaxSum=Seq[i];
        cout<<"������к�Ϊ:"<<MaxSum<<endl;   //������кͼ�Ϊ�����Ǹ�����
	}
	else
	{
	   for(i=0;i<n;i++)     //�ӵ�0λ����n-1λ�������е�ͷԪ��
	   {
		   for(j=i;j<n;j++)    //j=i���ӵ�iλ��ʼ�������е�βԪ�أ�ͷ�̶���βÿ������ƶ�һλ
		   {
			   sum=sum+Seq[j];   //�������к�
			   if(sum>MaxSum)    //�������MaxSum
				   MaxSum=sum;   //����MaxSum
		   }
		   sum=0;
	    }
	cout<<"������к�Ϊ:"<<MaxSum<<endl;
	}
}

void MaxSubSeq_2(int n,int *Seq)   //����(�����㷨�����ߴ���)��������⣬���㷨ʱ�临�Ӷ�ΪO(n)��Ϊ�����㷨
{
	int i,j,MaxSum=0,sum=0;   //MaxSumΪ������кͣ�sumΪ��ǰ���к�
	
	for(i=0;i<n;i++)     //�ж��Ƿ�Ϊȫ��
       if(Seq[i]>=0)
			break;
	if(i==n)   //�ϸ�ѭ�������˳�����������Ϊȫ�������
	{
		MaxSum=Seq[0];
		for(i=1;i<n;i++)
            if(Seq[i]>MaxSum)
				MaxSum=Seq[i];
        cout<<"������к�Ϊ:"<<MaxSum<<endl;   //������кͼ�Ϊ�����Ǹ�����
	}
	
	else   //��Ϊȫ�������
	{
		for(i=0;i<n;i++)
		{
		     sum=sum+Seq[i];   //��ͷ��ʼɨ�裬���ۼ�
			 if(sum<=0)   //�����ǰ���к�Ϊ������������ʹ����Ĳ��ֺ͸�������û�д�������
				 sum=0;    //��ǰ���к����㣬��ʼ��һ��
			 else
			 {
				 if(sum>MaxSum)  //���sum����MaxSum
					MaxSum=sum;    //����MaxSum,��ʱ���ı�sum,�����ۼ�
			 }
		}
		cout<<"������к�Ϊ:"<<MaxSum<<endl; 
	}
}
#endif