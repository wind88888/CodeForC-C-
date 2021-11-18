//二分查找
#include<iostream>
#include<stdio.h>

using namespace std;

#define MAXSIZE 100
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    int lenght;
};

int BinarySearch(List Tb1,ElementType K)
{//在表Tb1中查找关键字为K的数据元素
    int left,right,mid,NoFound=-1;

    left=-1;//初始左边界
    right=Tb1->lenght;//初始右边界
    while (left<=right)
    {
        mid=(left+right)/2;//计算中间元素坐标
        if (K<Tb1->Data[mid])     right=mid-1;//调整右边界
        else if(K>Tb1->Data[mid]) left=mid+1;//调整左边界
        else return mid;
    }
    return NoFound;    
}

int X[]={5,16,39,45,51,98,100,202,226,321,368,444,501};
int flag=0;

int binary_search(int temp,int bot,int top)
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
            return mid2;
        }
    }   
}

int binary_search_2(int temp)
{
    int mid2,top,bot,NoFound=-1;
    bot=-1;
    top=sizeof(X)/sizeof(X[0])-1;

    while (top>=bot){
        mid2=(top+bot)/2;
        if (temp<X[mid2])      top=mid2-1;//调整右边界
        else if (temp>X[mid2]) bot=mid2+1;//调整左边界
        else return mid2; 
    } 
    return NoFound;  
}

int main()
{
    int value;
    int n=sizeof(X)/sizeof(X[0]);
    cin>>value;
    
    cout<<binary_search(value,0,n-1)<<endl; 
    cout<<binary_search_2(value)<<endl;

    system("pause");
    return 0;
}