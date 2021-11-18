#include<iostream>
using namespace std;

int main()
{
    int i,j,n,k;//左右问题的循环变量，排序数目,原数组循环变量
    int mid;//数组中位数序号
    cout<<"请输入需要对多少个数进行排序"<<endl;
    cin>>n;
    int a[n];
    cout<<"请连续输入"<<n<<"个数"<<endl;
    for(k=0;k<n;k++)
        cin>>a[k];

    if(n%2)
        mid=(n-1)/2;//奇数
    else
        mid=n/2;    //不管奇偶，中位数都放在右问题

    int n1=mid+1,n2=n-mid+1;//计算左右数组各有多少个元素，最后多一个无穷元素
    int L[n1],R[n2];//开辟左右数组

    //开始赋值
    for(i=0;i<mid;i++)
        L[i]=a[i];
    L[mid]=12345677;
    for(j=0;j<n-mid;j++)
        R[j]=a[mid+j];
    R[n-mid]=12345678;

    //排序
    i=j=0;
    for(k=0;k<n;k++)
    {
        if(L[i]>R[j])
        {
            a[k]=R[j];
            //if(j<n2-1)//防止左右数组超额，j最大只能是n2-1
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