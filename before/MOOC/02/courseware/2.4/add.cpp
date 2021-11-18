//多项式加法运算
//输入输出要求同小白专场题意理解一样
#include<iostream>
//#include<stdio.h>
#include<stdlib.h> 
using namespace std;

struct PolyNode{
    int coef;//系数
    int expon;//指数
    struct PolyNode *link; //指向下一个节点的指针
};
typedef struct PolyNode *Polynomial;
//Polynomial P1,P2;

void Attach(int c,int e,Polynomial *pRear)
{
    //由于在本函数中需要改变当前结果表达式尾项指针的值
    //所以函数传递进来的是结点指针的地址，*pRear指向尾项
    //因为C语言是函数操作值的传递，而节点连接之后需要更改节点指针的位置到新插入的节点
    Polynomial P;

    P=(Polynomial)malloc(sizeof(struct PolyNode));//申请新结点
    P->coef=c;
    P->expon=e;
    P->link=NULL;
    //将P指向的新结点插入到当前结果表达式尾项的后面
    (*pRear)->link=P;
    *pRear=P;//修改pRear的值
}

int Compare(int x,int y)
{
    if (x>y)
        return 1;
    else if(x<y)
        return -1;
    else
        return 0;
}

Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;//结果多项式的头尾和临时指针
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));//为方便表头插入，先产生一个临时空结点作为结果多项式链表头
    front=rear;//由front记录结果多项式链表头结点
    while(P1&&P2)
        switch(Compare(P1->expon,P2->expon)){
        case 1://P1中的数据项指数较大
            Attach(P1->coef,P1->expon,&rear);
            P1=P1->link;
            break;
        case -1://P2中的数据项指数较大
            Attach(P2->coef,P2->expon,&rear);
            P2=P2->link;
            break;
        case 0://两数据项指数相等
            sum=P1->coef+P2->coef;
            if(sum) //注意判断系数和是否为0
            {
                Attach(sum,P1->expon,&rear);
            }
            P1=P1->link;
            P2=P2->link;
            break;
        }
//将未处理完的另一个多项式的所有节点依次复制到结果多项式中去
    for(;P1;P1=P1->link) Attach(P1->coef,P1->expon,&rear);//P1不空
    for(;P2;P2=P2->link) Attach(P2->coef,P2->expon,&rear);//P2不空
    rear->link=NULL;
    temp=front;
    front=front->link;//令front指向结果多项式第一个非零项
    free(temp);//释放临时空表头结点
    return front;
}

Polynomial ReadPoly()
{
    Polynomial P,Rear,t;
    int c,e,N;

    cin>>N;
    P=(Polynomial)malloc(sizeof(struct PolyNode));//链表头空节点
    P->link=NULL;
    Rear=P;
    while(N--)
    {
        cin>>c>>e;
        Attach(c,e,&Rear);//将当前项插入多项式尾部
    }
    t=P; P=P->link; free(t); // 删除临时生成的头结点
    return P;
}

void PrintPoly(Polynomial P)
{//输出多项式
    int flag=0;//辅助调整输出格式用
    if (!P)
    {
        printf("0 0\n");
        return;
    }

    while (P)
    {
        if (!flag)
        {
            flag=1;
        }
        else
        {
            printf(" ");
        }               
        printf("%d %d",P->coef,P->expon);
        P=P->link;
    }
    cout<<endl;
}

int  main()
{
    Polynomial P1,P2,PS;
    P1=ReadPoly();
    P2=ReadPoly();
    PS=PolyAdd(P1,P2);
    PrintPoly(PS);

    system("pause");
    return 0;
}