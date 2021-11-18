#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct List *link;
typedef struct List Lnode;

struct List
{
    ElemType data;
    struct List *next;
};

link setnull(link Head)//释放链表
{
    link p;
    p=Head;
    while(p)
    {
        p=p->next;
        free(Head);
        Head=p;
    }
    return Head;
}

link insert(link Head,ElemType X,int i)//插入结点
{
    link NewPoint,p=Head;
    int j=1;
    NewPoint=(link)malloc(sizeof(Lnode));
    NewPoint->data=X;
    if(i==1)
    {
        NewPoint->next=Head;
        Head=NewPoint;
    }
    else
    {
        while(j<i-1&&p->next!=NULL)
        {
            p=p->next;
            j++;
        }
        if(j==i-1)
        {
            NewPoint->next=p->next;
            p->next=NewPoint;
        }
        else
        {
            printf("insert is failure, i is not right!");
        }
    }
    return Head;   
}

link creat(link Head)
{
    ElemType newdata;
    link newpoint;

    Head=(link)malloc(sizeof(Lnode));
    printf("please intput number: \n");
    scanf("%d",&newdata);
    Head->data=newdata;
    Head->next=NULL;

    while(1)
    {
        newpoint=(link)malloc(sizeof(Lnode));
        printf("please input number:input '-1' means exit\n");
        scanf("%d",&newdata);
        if(newdata==-1)
            return Head;
        else
        {
            newpoint->data=newdata;
            newpoint->next=Head;
            Head=newpoint;
        }
    }
    return Head;
}