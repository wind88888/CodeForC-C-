//栈的链式存储实现
typedef int ElementType;

typedef struct SNode *PtrtoSNode
{
    ElementType Data;
    PtrtoStack Next;
};

typedef PtrtoStack Stack;

Stack CreatStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty(Stack S)
{
    return (S->Next == NULL);
}

bool Push(Stack S,ElementType X)
{
    //新创建个节点存储X，然后接在S后面
    Stack P;
    P = (Stack)malloc(sizeof(struct SNode));
    P->Data = X;
    P->Next = S->Next;
    S->Next = P;
    return true;
}

ElementType Pop(Stack S)
{
    Stack P;
    ElementType temp;

    if (IsEmpty(S)){
        cout << "栈空";
        return ERROR;
    }
    else
    {           
        P = S->Next;
        S->Next = P->Next;
        temp = P->Data;
        free(P);
        return temp;
    }

}