//P116 例4.3输出二叉树的所有结点  例4.4求出二叉树的高度
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

typedef struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}; 

void PreorderPrintLeaves(BinTree BT)
{
    if (BT){
        if (!BT->Left && !BT->Right)
            cout << BT->Data;
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
}

int GetHeight(BinTree BT)
{
    int HL, HR, MaxH;

    if (BT){
        HL = GetHeight(BT->Left);
        HR = GetHeight(BT->Right);
        MaxH = HL > HR ? HL : HR;
        return (MaxH + 1); 
    }
    else return 0;
}