#include"HRN.h"
#include<iostream>
#include<stdio.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n,i;
	cout<<"��������Ҫ���ȵ��ܹ�������";
	cin>>n;
	Job *jobs=new Job[n];
	cout<<"�밴˳��������ҵ����name������ʱ��AT������ʱ��RT��"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>jobs[i].name>>jobs[i].AT>>jobs[i].RT;
	}
	HRN(jobs,n);
	for(i=0;i<n;i++)
		jobs[i].status=0;
	SJF(jobs,n);
	FCFS(jobs,n);
	delete[] jobs;
	return 0;
}