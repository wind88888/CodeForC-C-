#include<iostream>
using namespace std;

int shuzu_sum(int left,int right);
int a[]={3,4,-2,1,5,-1,2,6};
int main()
{
    int n,value;
    n=sizeof(a)/sizeof(a[0]);
    value=shuzu_sum(0,n-1);
    cout<<value<<endl;
    system("pause");
    return 0;
}

int shuzu_sum(int left,int right)
{
    int sum=0;
    int i;
    if(left==right)
    {
        if(a[left]>0)
            sum=a[left];
        else
            sum=0;
    }      
    else
    {
        int mid=(left+right)/2;
        int max1=shuzu_sum(left,mid);
        int max2=shuzu_sum(mid+1,right);
        int sum1=0;
        int sum2=0;
        for(i=mid;i>=left;i--)
        {
            sum1+=a[i];
            if(sum1>sum2)
                sum2=sum1;
        }
        int sum3=0;
        int sum4=0;
        for(i=mid+1;i<=right;i++)
        {
            sum3+=a[i];
            if(sum3>sum4)
                sum4=sum3;
        }
        sum=sum2+sum4;
        if(sum<max1)
            sum=max1;
        if(sum<max2)
            sum=max2;
        return sum;
    }  
}