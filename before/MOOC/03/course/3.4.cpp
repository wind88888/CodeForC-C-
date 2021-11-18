//层序生成二叉树
#define NoInfo 0
typedef int ElementType;

typedef int Position;
struct QNode {
    ElementType *Data;     /* 存储元素的数组 */
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

typedef struct TNode *Position;
typedef Position BinTree;

typedef struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}; 

BinTree CreatBinTree()
{
    ElementType Data;
    BinTree BT,T;
    Queue Q = CreatQueue();

    //建立根节点(第一个结点)
    cin >> Data;
    if (Data != NoInfo){
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q, BT);
    }
    else
        return NULL;//若第一个数据为0，则为空树
    
    while (!(IsEmpty(Q))){
        T = DeleteQ(Q);
        cin >> Data;
        if (Data != NoInfo){
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        else
            return T->Left = NULL;
        
        cin >> Data;
        if (Data != NoInfo){
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            AddQ(Q, T->Right);
        }
        else
            return T->Right = NULL;
    }

    return BT;
}