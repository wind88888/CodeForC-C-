//二分查找
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput()
{
    int n;
    std::cin>>n;
    List LP;

    LP=(List)malloc(sizeof(struct LNode));

    for (int i=1; i<=n; i++){
        std::cin>>LP->Data[i];
    }
    return LP;
}
Position BinarySearch( List L,  ElementType X )
{
    int left,right;
    left=1;//此处是坑！！！题目中说了注意：元素从下标1开始存储
    right=L->Last;
    int mid;
    int value=0;//要设初值
    while(right>=left)
    {
        mid=(left+right)/2;
        if(X==L->Data[mid])
        {
            value=mid;
            break;
        }
        else if(X>L->Data[mid])
            left=mid+1;
        else
        {
            right=mid-1;
        }   
    }
    if(!value)
        return NotFound;
    else
    {
        return value;        
    }
}