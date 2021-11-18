#include<iostream>
using namespace std;

int X[]={4,9,6,3,5,2,8,1};//排序原数组
int a[10];
static int count=0;//计数

void merge_sort(int L,int R);//归并排序

int main()
{
    int i,j,n;
    n=sizeof(X)/sizeof(X[0]);//计算数组元素个数
    merge_sort(0,n-1);
    for(i=0;i<n;i++)
         cout<<X[i]<<" ";
    cout<<endl;
    cout<<count<<endl;

    system("pause");
    return 0;
}
void merge_sort(int L,int R)
{
    int i,j,k;
        if(L>=R)
        return;
    int mid=(L+R)/2;//求得中间元素序号
    merge_sort(L,mid);//求解左问题
    merge_sort(mid+1,R);//求解右问题
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
          //当左问题元素大时，对于已排好序而言，代表包括本身及其右边的元素都比右问题元素大
            count=count+mid-i+1;
        }
    }   
}