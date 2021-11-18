#include<iostream>
using namespace std;
#define size 100
int m[size][size],s[size][size];
int n;
int p[size];

int matricx_chain_order(int q,int n)
{
    int i,j;
    int k,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            m[i][j]=-1;
            s[i][j]=-1;
        }
    }  

    m[q][n]=7384173477389;
    
    if(q == n)
    {
        m[q][n]=0;
//       return;
    }  

    for(k=q;k<=n-1;k++)
    {
        int a=m[q][k];
        int b=m[k+1][n];
        if(a==-1)
        {
            a=matricx_chain_order(q,k);
        }
        if(b==-1)
        {
            b=matricx_chain_order(k+1,n);
        }
        t=a+b+p[q-1]*p[k]*p[n];
        if(t<m[q][n])
        {
            m[q][n]=t;
            s[q][n]=k;
        }
    }
}
int main()
{
    cout<<"���������ĸ���n : "<<endl;
	cin>>n;
	int i,j;
	cout<<"����������ÿ����������������һ�������������"<<endl;
	for(i=0;i<=n;i++)
		cin>>p[i];
	matricx_chain_order(1,n); 

    cout<<"��С��������ֵΪ��"<<m[1][n]<<endl;
	cout<<"�Ͽ���λ��Ϊ��"<<s[1][n]<<endl;

    system("pause");
	return 0;
}