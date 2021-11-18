//二叉树的遍历

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

typedef struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}; 

//递归
//中序遍历,左中右
void InorderTraversal(BinTree BT)
{
    if (BT){
        InorderTraversal(BT->Left);
        cout << BT->Data << endl;
        InorderTraversal(BT->Right);
    }
}

//先序遍历，中左右
void PreorderTraversal(BinTree BT)
{
    if (BT)
    {
       cout << BT->Data << endl;
       PreorderTraversal(BT->Left);
       PreorderTraversal(BT->Right);
    }
}

//后续遍历，左右中
void PostorderTraversal(BinTree BT)
{
    if (BT)
    {
       PostorderTraversal(BT->Left);
       PostorderTraversal(BT->Right); 
       cout << BT->Data << endl;
    }
}

//非递归，堆栈实现
//中序遍历
void InorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreatStack();
    T = BT;
    while (T || !(IsEmpty(S))){
        while (T){
            Push(S,T);
            T->Left;
        }
        if (!(IsEmpty(S))){
            T = Pop(S);
            cout << T->Data << endl;
            T->Right;
        }
    }
}

//先序遍历
void PreorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreatStack();
    T = BT;
    while (T || !(IsEmpty(S))){
        while (T){
            cout << T->Data << endl;
            Push(S,T);
            T->Left;
        }
        if (!(IsEmpty(S))){
            T = Pop(S);
            T->Right;
        }
    }
}

//后序遍历
void postorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreatStack();
    T = BT;
    BinTree LT = NULL;
    while (T || !(IsEmpty(S))){
        while (T){
            Push(S,T);
            T->Left;
        }//遍历完左子树
        if (!(IsEmpty(S)))
        {
            T = Pop(S);
            if (T->Right == NULL || T->Right == LT){//如果右节点为空或已输出时，打印当前节点
                cout << T->Data << endl;
                LT = T;
                T = NULL;
            }
            else
            {
                Push(S,T);//二次入栈   
                T->Right;
            }
        }
    }
}

//层序遍历
void LevelorderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;

    if (!BT) return;

    Q = CreatQueue();
    AddQ(Q, BT);

    while (!(IsEmpty(Q))){
        T = Delete(Q);
        cout << T->Data;
        if (T->Left) AddQ(Q, T->Left);
        if (T->Right) AddQ(Q, T->Right);
    }
}