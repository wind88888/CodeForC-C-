//二叉搜索树的插入
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

typedef struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}; 

BinTree Insert(BinTree BST, ElementType X)
{
    if (!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else{
        if (X > BST->Data)
            BST->Right = Insert(BST->Right,X);
        else if(X < BST->Data)
            BST->Left = Insert(BST->Left,X);
    }
    return BST;

}