#include<iostream>
using namespace std;

void merge(int X[],int p,int r,int count);
void merge_sort(int X[],int p,int r,int count);
int main()
{
    int count=0,n;
    int X[]={4,3,2};
    n=sizeof(X)/sizeof(X[0]);
    merge_sort(X,0,n-1,count);
    return count;
    system("pause");
    return 0;
}

void merge(int X[],int p,int r,int count)
{
    int i,j,k;
    int n=p-r+1;
    int mid;

    if(n%2)
        mid=(n-1)/2;//奇数
    else
        mid=n/2;    //不管奇偶，中位数都放在右问题

    int n1=mid+1,n2=n-mid+1;
    int L[n1],R[n2];

    for(i=0;i<n1-1;i++)
        L[i]=X[i];
    L[n1-1]=12451376125467;
    for(j=n1;j<n2-1;j++)
        R[j]=X[j];
    R[n2-1]=12451376125468;

    i=j=0;
    for(k=0;k<n;k++)
    {
        if(L[i]>R[j])
        {
            X[k]=R[j];
            //if(j<n2-1)//防止左右数组超额，j最大只能是n2-1
               j++;
               count=count+n1-i;
        }
        else
        {
            X[k]=L[i];
            //if(i<n1-1)
                i++;
        }
    }
}

void merge_sort(int X[],int p,int r,int count)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(X,p,q,count);
        merge_sort(X,q+1,r,count);
        merge(X,p,q,count);
    }
}