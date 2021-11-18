//循环队列(顺序存储的队列)

typedef int ElementType;
typedef int Position;
typedef struct QNode *PtrtoQNode;
{
    Position Front;
    Position Rear;
    ElementType *Data;
    int Maxsize;
};

typedef PtrtoQNode Queue;

Queue CreateQueue(int Maxsize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(Maxsize*sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->Maxsize = Maxsize;
    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear + 1) % Q->Maxsize) == Q->Front;
}

bool IsEmpty(Queue Q)
{
    return (Q->Rear == Q->Front);
}

bool AddQ(Queue Q, ElementType X)
{
    if (IsFull(Q))
    {
        cout << "队列已满";
        return false;
    }
    else
    {
        //Q->Rear++;
        Q->Rear = (Q->Rear+1) % Q->Maxsize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

ElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        cout << "队列已空";
        return ERROR;
    }
    else
    {
        Q->Front = (Q->Front+1) % Q->Maxsize;
        return  Q->Data[Q->Front];
    }
}