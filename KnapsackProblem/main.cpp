#include"KnapsackProblem.h"

int main()
{
	int n,*w,*v,c,i;
	cout<<"��������Ʒ����:";
	cin>>n;
	w=new int[n];
	v=new int[n];
	cout<<"�����������Ʒ������:";
	for(i=0;i<n;i++)
		cin>>w[i];
	cout<<"�������Ӧ��Ʒ�ļ�ֵ:";
	for(i=0;i<n;i++)
		cin>>v[i];
	cout<<"�����뱳�����������:";
	    cin>>c;
	KnapspackProblem(n,w,v,c);
	delete[] w;
	delete[] v;
	return 0;
}