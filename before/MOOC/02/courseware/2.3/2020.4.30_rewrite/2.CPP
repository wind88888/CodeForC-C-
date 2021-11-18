//队列的栈式存储实现
typedef int ElementType;
typedef struct Node * PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode * PtrToQNode;
struct QNode
{
    Position Front,Rear;
    int Maxsize;
};
typedef PtrToQNode Queue;

bool IsEmpty(Queue Q)
{
    return (Q->Front == NULL);
}

ElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;

    if (IsEmpty(Q))
    {
        cout << "队列空";
        return ERROR;
    }
    else
    {
        FrontCell = Q->Front;
        if (Q->Front == Q->Rear)
            Q->Front = Q->Rear = NULL;
        else
        {
            Q->Front = Q->Front->Next;
        }
        FrontElem = FrontCell->Data;

        free(FrontCell);
        return FrontElem;
        
    }
    
}