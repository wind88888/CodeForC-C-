#include<iostream>
using namespace std;

int main()
{
    int i,j,n,k;//���������ѭ��������������Ŀ,ԭ����ѭ������
    int mid;//������λ�����
    cout<<"��������Ҫ�Զ��ٸ�����������"<<endl;
    cin>>n;
    int a[n];
    cout<<"����������"<<n<<"����"<<endl;
    for(k=0;k<n;k++)
        cin>>a[k];

    if(n%2)
        mid=(n-1)/2;//����
    else
        mid=n/2;    //������ż����λ��������������

    int n1=mid+1,n2=n-mid+1;//��������������ж��ٸ�Ԫ�أ�����һ������Ԫ��
    int L[n1],R[n2];//������������

    //��ʼ��ֵ
    for(i=0;i<mid;i++)
        L[i]=a[i];
    L[mid]=12345677;
    for(j=0;j<n-mid;j++)
        R[j]=a[mid+j];
    R[n-mid]=12345678;

    //����
    i=j=0;
    for(k=0;k<n;k++)
    {
        if(L[i]>R[j])
        {
            a[k]=R[j];
            //if(j<n2-1)//��ֹ�������鳬�j���ֻ����n2-1
               j++;
        }
        else
        {
            a[k]=L[i];
            //if(i<n1-1)
                i++;
        }
    }
    for(k=0;k<n;k++)
        cout<<a[k]<<" ";
    system("pause");
    return 0;
}