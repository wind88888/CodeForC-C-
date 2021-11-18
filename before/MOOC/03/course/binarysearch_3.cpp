//二分查找
//链表数组，顺序存储
#include<iostream>
#include<stdio.h>

using namespace std;

#define MAXSIZE 15
typedef int ElementType;
typedef struct LNode *List;
struct LNode{
    ElementType * Data;
    int lenght;
};

List CreatEmpty(int n)
{
    List Tb = (List)malloc(sizeof(struct LNode));
    Tb->Data = (ElementType*)malloc(MAXSIZE*sizeof(ElementType));
    Tb->lenght = n;
    return Tb;
} 

List CreatFull(List Tb, int n)
{
    int i = 1;
    while (n--)
    {
        cin >> Tb->Data[i++];
    }
    return Tb;
}

int BinarySearch(List Tb1,ElementType K)
{//在表Tb1中查找关键字为K的数据元素
    int left,right,mid,NoFound=-1;

    left=1;//初始左边界
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

int main()
{
    int num;
    int n;
    cin >> n;
    
    List Tb = CreatEmpty(n);
    List Tb1 = CreatFull(Tb,n);//第一行输入有多少个元素
    //第二行输入各元素值 
    cin >> num;//第三行输入要查找的元素
    cout << BinarySearch(Tb1,num) << endl;

    system("pause");
    return 0;
}