//归并排序
#include<iostream>
using namespace std;


void merge_sort(int L,int R,float X[],float a[]);//归并排序

int main()
{
    int i,j,n;
    float X[]={1.11,5.11,2.06,7.06,3.13,9.13,12.07,16.07,14.03,25.03,19.18,22.18,23.13,29.13,24.04,28.04};//排序原数组
    float a[100];
    n=sizeof(X)/sizeof(X[0]);//计算数组元素个数
    merge_sort(0,n-1,X,a);
    for(i=0;i<n;i++)
         cout<<X[i]<<" ";
    cout<<endl;

    system("pause");
    return 0;
}
void merge_sort(int L,int R,float X[],float a[])
{
    int i,j,k;
    if(L>=R)
        return;
    int mid=(L+R)/2;//求得中间元素序号
    merge_sort(L,mid,X,a);//求解左问题
    merge_sort(mid+1,R,X,a);//求解右问题
    for(i=L;i<=R;i++)//将要排序的元素赋值给备用数组
        a[i]=X[i];
    i=L,j=mid+1;//归并两部分分别从最左边开始扫描比较
    for(k=L;k<=R;k++)//归并排序 
    {
        if(i<=mid&&((j>R)||a[i]<a[j]))//左问题未到边界，右问题未超边界。取较小元素
        {
            X[k]=a[i++];
        }   
        else
        {
            X[k]=a[j++]; 
        }
    }   
}