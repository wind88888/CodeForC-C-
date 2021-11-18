#include<iostream>
using namespace std;

int search(int left,int right);
int a[]={1,3,4,7,9,12,14,16};//原数组
int b[]={7,9,12,14,16,1,3,4};//循环移位后数组

int main()
{
    int n,num;
    n=sizeof(a)/sizeof(a[0]);

    num=search(0,n-1);
    cout<<num<<endl;//num-0
    system("pause");
    return 0;
}
int search(int left,int right)
{
    int mid;
    mid=(left+right)/2;

    if(right-left==1)//在最后两个元素中取小者即为所求最小数
    {
        if(b[left]>b[right])
            return right;
        else
            return left;
    }

    if(b[right]&&b[left]>b[right])//最小元素在右半段
        search(mid,right);
    else if(b[mid]>b[left]&&b[right]>b[left])//最小元素在左半段
        search(left,mid);
    else if(b[left]>b[mid]&&b[right]>b[mid])
        {
            if(b[left]>b[right])//最小元素在左半段
                search(left,mid);
            else
                search(mid,right);//最小元素在右半段
        }
}