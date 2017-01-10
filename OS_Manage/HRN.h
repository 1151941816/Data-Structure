#ifndef HRN_H
#define HRN_H
#include<iostream>
#include<iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::ostream;

struct Job
{
	char name[8];
	int AT;  //arrive time ����ʱ��
	int RT;  //running time ����ʱ��
	int ST;  //start time ��ʼʱ��
	int WT;  //waiting time �ȴ�ʱ��
	int ET;  //end time ����ʱ��
	int status;  //��¼������Ƿ��ѱ����
	double resp;   //��Ӧ��

	Job()
	{
		status=0;  //��ʼ��Ϊ0����ʾ��δ�����
	}
	friend ostream & operator<<(ostream &out,const Job &job)
	{
	   out<<setw(6)<<job.name<<setw(6)<<job.AT<<setw(6)<<job.RT
		<<setw(6)<<job.ST<<setw(6)<<job.WT<<setw(6)<<job.ET<<endl;
	   return out;
	}
};

void HRN(Job *jobs,int n)  //�����Ӧ���㷨
{
	cout<<"��Ӧ�ȸ��������㷨ִ��˳��"<<endl;
	cout<<setw(6)<<"JOBS"<<setw(6)<<"AT"<<setw(6)<<"RT"<<setw(6)<<"ST"
		<<setw(6)<<"WT"<<setw(6)<<"ET"<<endl;
	jobs[0].ST=jobs[0].AT;   //�ȴ����һ��
	jobs[0].WT=0;
	jobs[0].ET=jobs[0].ST+jobs[0].RT;
	cout<<jobs[0];
	jobs[0].status=1;  //������ѽ��
	int i=1,count,max=1,pre=0,c=1,flag=0;
	for(count=1;count<n;count++)   //����n-1���������
	{
	    for(i=1;jobs[i].AT<=jobs[pre].ET;i++)   //����i�����ǰһ(�Ѵ������)��������֮ǰ�������ѭ��
		{
		   if(jobs[i].status==0)    //���Ҹ������δ������
		    {
				if(c==1)     //��һ��δ���������ҵ����
					max=i;    //��maxΪ������ҵ���
				jobs[i].resp=(jobs[pre].ET-jobs[i].AT)*1.0/jobs[i].RT;   //������Ӧ��
				if(jobs[i].resp>jobs[max].resp)
					max=i;     //����max���ҵ������Ӧ��
				c++;
				flag=1;
		    }
	    }
		if(flag==0)  //����ǰһ(�Ѵ������)��������֮ǰ����Ĺ������Ѵ����꣬��δ����ĵ�i������ŵ���
		{
			jobs[i].ST=jobs[i].AT;   //�����i��
			jobs[i].WT=0;     //����ȴ�ʱ��Ϊ0
			jobs[i].ET=jobs[i].ST+jobs[i].RT;
			cout<<jobs[i];
			jobs[i].status=1;
			pre=i;
		}
		else
		{
		   jobs[max].ST=jobs[pre].ET;    //���������������Ӧ�ȵĹ���
		   jobs[max].WT=jobs[pre].ET-jobs[max].AT;
		   jobs[max].ET=jobs[max].ST+jobs[max].RT;
		   cout<<jobs[max];    //�����һ��
		   jobs[max].status=1;   //�������Ӧ�ȵĹ����Ѵ����꣬status��ֵΪ1
		   pre=max;   //���˾��������Ӧ�ȵĹ�����Ϊǰһ��
		}
		c=1;
		flag=0;
	}
	cout<<"ƽ���ȴ�ʱ�䣺";
	int sumWT=0;
	double aveWT;
	for(i=0;i<n;i++)
		sumWT=sumWT+jobs[i].WT;
	aveWT=sumWT*1.0/n;
	cout<<aveWT<<endl;
	cout<<endl;
}

void SJF(Job *jobs,int n)   //�����ҵ�����㷨
{
	cout<<"�����ҵ�����㷨ִ��˳��"<<endl;
	cout<<setw(6)<<"JOBS"<<setw(6)<<"AT"<<setw(6)<<"RT"<<setw(6)<<"ST"
		<<setw(6)<<"WT"<<setw(6)<<"ET"<<endl;
	int min=0,i,count,pre,c=1,flag=0;
	for(i=1;jobs[i].AT==jobs[0].AT;i++)   //���м�����ҵͬʱ���ȵ���
	{
		if(jobs[i].RT<jobs[min].RT)   //�ҳ������ҵ
			min=i;
	}
	jobs[min].ST=jobs[min].AT;
	jobs[min].WT=0;
	jobs[min].ET=jobs[min].ST+jobs[min].RT;
	cout<<jobs[min];
	jobs[min].status=1;  //������ҵ�ѽ��
	pre=min;
	for(count=1;count<n;count++)   //����n-1���������
	{
		for(i=0;jobs[i].AT<=jobs[pre].ET;i++)  //����i�����ǰһ(�Ѵ������)��������֮ǰ�������ѭ��
		{
             if(jobs[i].status==0)   //���Ҹ������δ������
			 {
				 if(c==1)   //��һ��δ���������ҵ����
					 min=i;   //��minΪ������ҵ���
				 if(jobs[i].RT<jobs[min].RT)    
					 min=i;   //����min���ҳ������ҵ
				 c++;
				 flag=1;
			 }
		}
		if(flag==0)   //����ǰһ(�Ѵ������)��������֮ǰ����Ĺ������Ѵ����꣬��δ����ĵ�i������ŵ���
		{
			jobs[i].ST=jobs[i].AT;   //�����i��
			jobs[i].WT=0;     //����ȴ�ʱ��Ϊ0
			jobs[i].ET=jobs[i].ST+jobs[i].RT;
			cout<<jobs[i];
			jobs[i].status=1;
			pre=i;
		}
		else
		{
		    jobs[min].ST=jobs[pre].ET;   //������һ��
		    jobs[min].WT=jobs[pre].ET-jobs[min].AT;
		    jobs[min].ET=jobs[min].ST+jobs[min].RT;
		    cout<<jobs[min];
		    jobs[min].status=1;   //������Ѵ�����
		    pre=min;
		}
		c=1;
		flag=0;
	}
	cout<<"ƽ���ȴ�ʱ�䣺";
	int sumWT=0;
	double aveWT;
	for(i=0;i<n;i++)
		sumWT=sumWT+jobs[i].WT;
	aveWT=sumWT*1.0/n;
	cout<<aveWT<<endl;
	cout<<endl;
}

void FCFS(Job *jobs,int n)    //�����ȷ����㷨
{
	cout<<"�����ȷ����㷨ִ��˳��"<<endl;
	cout<<setw(6)<<"JOBS"<<setw(6)<<"AT"<<setw(6)<<"RT"<<setw(6)<<"ST"
		<<setw(6)<<"WT"<<setw(6)<<"ET"<<endl;
	int i;
	jobs[0].ST=jobs[0].AT;   //�ȴ����һ��
	jobs[0].WT=0;
	jobs[0].ET=jobs[0].ST+jobs[0].RT;
	cout<<jobs[0];
	for(i=1;i<n;i++)    //���δ����������n-1��
	{
		if(jobs[i].AT>jobs[i-1].ET)
		{
			jobs[i].ST=jobs[i].AT;   //�����i��
			jobs[i].WT=0;     //����ȴ�ʱ��Ϊ0
			jobs[i].ET=jobs[i].ST+jobs[i].RT;
			cout<<jobs[i];
		}
		else
		{
		    jobs[i].ST=jobs[i-1].ET;
		    jobs[i].WT=jobs[i-1].ET-jobs[i].AT;
		    jobs[i].ET=jobs[i].ST+jobs[i].RT;
		    cout<<jobs[i];
		}
	}
	cout<<"ƽ���ȴ�ʱ�䣺";
	int sumWT=0;
	double aveWT;
	for(i=0;i<n;i++)
		sumWT=sumWT+jobs[i].WT;
	aveWT=sumWT*1.0/n;
	cout<<aveWT<<endl;
	cout<<endl;
}
#endif