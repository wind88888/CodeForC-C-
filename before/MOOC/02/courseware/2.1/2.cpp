//链式存储的的线性表
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

//求表长
int Length(List L)
{
    List p=L;//p指向表的第一个结点
    int j=0;
    while(p)
    {
        p=p->Next;
        j++;       //当前p指向的是第j个结点
    }
    return j;
}

/* 查找 */
#define ERROR NULL
//按值查找 
Position Find( List L, ElementType X )
{
    Position p = L; /* p指向L的第1个结点 */
 
    while ( p && p->Data!=X )
        p = p->Next;
 
    /* 下列语句可以用 return p; 替换 */
    if ( p )
        return p;
    else
        return ERROR;
}
//按序号查找
Position FindKth(int K,List L)
{
    List p=L;/* p指向L的第1个结点 */
    int i=1;
    while (p && i<K)
    {
        p=p->Next;
        i++;
    }
    if(i==K)
        return p;//找到第K个，返回指针
    else
    {
        return ERROR;//否则返回空
    }
}
 
/* 带头结点的插入 */
//视频插入方法：序列位序（从1开始）
Position InsertKth(ElementType X,int i,List L)
{
    List p,s;
    if (i==1)//新结点插入在表头
    {
        s=(List)malloc(sizeof(struct LNode));//申请、填装结点
    }
    s->Data=X;
    s->Next=L;
    return s;//返回新链表的头指针
}
    p=FindKth(i-1,L);//查找第i-1个结点
    if (p==NULL)
    {
        printf("参数i错");
        return NULL;
    }
    else
    {
        s=(List)malloc(sizeof(struct LNode));//申请、填装结点
        s->Data=X;
        s->Next=p->next;//新结点插入在第i-1个结点的后面
        p->next=s;
        return L;//返回链表的头指针
    }
    

/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert( List L, ElementType X, Position P )
{ /* 这里默认L有头结点 */
    Position tmp, pre;
 
    /* 查找P的前一个结点 */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next );//从头结点开始往后找。当到末尾结点下一个或者到P结点前一个时退出循环            
    if ( pre==NULL ) { /* P所指的结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 在P前插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        tmp->Data = X; 
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}
 
/* 带头结点的删除 */
//序列位序（从1开始）
Position DeleteKth(int i,List L)
{
    List p,s;
    if(i==1)//删除表的第1个结点
    {
        s=L;//s指向第一个结点
        if(L!=NULL) L=L->Next;//从链表中删除
        else return NULL;//L本身为空
        free(s);
        return L;//返回头结点
    }
    p=FindKth(i-1,L);//查找第i-1个结点
    if(p->Next==NULL)
        printf("第%d个结点不存在",i); return NULL;
    else
    {
        s=p->next;      //s指向第i个结点
        p->next=s->next;//从链表中删除
        free(s);        //释放被删除结点
        return L;
    }

}
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool Delete( List L, Position P )
{ /* 这里默认L有头结点 */
    Position tmp, pre;
 
    /* 查找P的前一个结点 */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
    if ( pre==NULL || P==NULL) { /* P所指的结点不在L中 */
        printf("删除位置参数错误\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 将P位置的结点删除 */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}