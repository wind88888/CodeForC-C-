//线性表的链式存储实现
#define ERROR -1

typedef int ElementType;

typedef struct Lnode *PtrtoLnode{
    ElementType Data;
    PtrtoLnode Next;
};

typedef PtrtoLnode Position;
typedef PtrtoLnode List;

int Length(List L)
{
    int count=0;
    List p = L;
    while (p){
        count++;
        p = p->Next;
    }
    return count;
}

ElementType FindKth(List L,int K)//返回位序K的元素
{
    List p = L;
    int cnt = 0；//位序从1开始，不是0
    while (p && cnt < K){//跳出循环有2种情况：(1)p为null(2)cnt==k
        p = p->Next;
        cnt++;
    }

    if (p && (cnt == K))//只有p不为空且cnt==K时
        return p->Data;
    else
    {
        return ERROR;
    }
}

Position Find(List L, ElementType X)//返回查找元素X的位置
{
    List p = List;

    while (p && p->Data != X)
        p = p->Next;

    if (p)
        return p;
    else
    {
        return ERROR;
    }
} 

List Insert(List L, ElementType X,int K)//在位序K插入元素X
{
    Position temp;
    Position p = L;

    temp = (Position)malloc(sizeof(struct Lnode));
    temp->Data =  X;
    
    if (i == 1){
        temp->Next = L;
        return temp;
    }
    else
    {
        int cnt = 1;
        while (p && (cnt < K-1)){
            cnt++;
            p = p->Next;
        }

        if (p && (cnt == K-1)){
            temp->Next = p->Next;
            p->Next = temp;
            return L;//不能返回p,它的地址已经变成位序K-1的地址了，但是L还是首地址
        }
        else
        {
            cout << "输入位置错误";
            free(temp);
            return NULL;
        }
    }
}

bool Delete(List L,int K)//删除位序K的元素
{
    Position p = L;
    Position temp;
    int cnt = 0;

    while (p && cnt < K-1){
        cnt++;
        p = p->Next;
    }

    if (p && (cnt == K-1) && p->Next == NULL){//注意p->Next == NULL
        temp = p->Next;
        p->Next = temp->Next;
        free(temp);
        return ture;
    }
    else
    {
        cout << "输入位置错误";
        free(temp);
        return false;
    }
}