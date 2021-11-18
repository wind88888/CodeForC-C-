#include<iostream>
using namespace std;

int X[]={1,7,9,3,16,12,4,3};
int a[10];
int flag=0;

void merge_sort(int L,int R);
void binary_search(int temp,int bot,int top);
int main()
{
    int i,j,n,temp;    
    n=sizeof(X)/sizeof(X[0]);

    merge_sort(0,n-1);//归并排序
    for(i=0;i<n;i++)
         cout<<X[i]<<" ";
    cout<<endl;

    int x=15;
    for(i=0;i<n;i++)
    {
        temp=x-X[i];
        binary_search(temp,i,n-1);//二分法查找
        if(flag==1)
        {
            cout<<"存在"<<endl;
            break;
        }
    }
    if(!flag)
        cout<<"不存在"<<endl;

    system("pause");
    return 0;
}
void merge_sort(int L,int R)
{
    int i,j,k;
        if(L>=R)
        return;
    int mid=(L+R)/2;
    merge_sort(L,mid);
    merge_sort(mid+1,R);
    for(i=L;i<=R;i++)
        a[i]=X[i];
    i=L,j=mid+1;
    for(k=L;k<=R;k++) 
    {
        if(i<=mid&&((j>R)||a[i]<a[j]))
        {
            X[k]=a[i++];
        }   
        else
        {
            X[k]=a[j++]; 
        }
    }   
}
void binary_search(int temp,int bot,int top)
{
    int mid2;
    mid2=(top+bot)/2;
    if(top>=bot)
    {
        if(X[mid2]<temp)
        {
            binary_search(temp,mid2+1,top);
        }
        else if(X[mid2]>temp)
        {
            binary_search(temp,bot,mid2-1);
        }
        else
        {
            flag=1;//找到了tmep
        }
    }   
}