#include <iostream>
using namespace std;
#define size 100
int m[size][size],s[size][size];
int n;
int p[size];

int matricx_chain_order()
{
    int i,j,x,k;
    int q;
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(x=1;x<=n-1;x++)
    {
        for(i=1;i<=n-x;i++)
        {
            j=i+x;
            m[i][j]=589285450;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
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
	matricx_chain_order(); 

    cout<<"��С��������ֵΪ��"<<m[1][n]<<endl;
	cout<<"�Ͽ���λ��Ϊ��"<<s[1][n]<<endl;

    system("pause");
	return 0;
}