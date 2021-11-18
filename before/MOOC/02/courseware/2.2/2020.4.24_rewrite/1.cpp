//栈的顺序存储实现
typedef int Position;
typedef int ElementType;

typedef struct SNode *PtrtoSNode
{
    ElementType *Data;
    Position Top;
    int Maxsize;
};

typedef PtrtoSNode Stack;

Stack CreateStack(int Maxsize)
{
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(sizeof(ElementType)*Maxsize);
    S->Top = -1;
    S->Maxsize = Maxsize;
    return S;
}

bool IsFull(Stack S)
{
    return (S->Top == S->Maxsize-1);    
}

bool Push(Stack S, ElementType X)
{
    if (IsFull(S))
    {
        cout << "栈满";
        return false;
    }
    else
    {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return (S->Top == -1);    
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        cout << "栈空";
        return ERROR;
    }
    else
    {
        return S->Data[(S->Top)--];
    }
    
}