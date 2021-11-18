//二叉搜索树的删除
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

typedef struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}; 

BinTree Delete(BinTree BST, ElementType X)
{
    Position Tmp;
    if (!BST)
        cout << "要删除的元素未找到";
    else{
        if (X > BST->Data )
            BST->Right = Delete(BST->Right,X);
        else if (X < BST->Data )
            BST->Left = Delete(BST->Left,X);
        else{
            if (BST->Left && BST->Right)
            {
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right,BST->Data); 
            }
            else
                Tmp = BST;
                if (!BST->Left)//有右节点或无左右节点
                    BST = BST->Right;
                else
                    BST = BST->Left;
                free(Tmp);
        }
    }
    return BST;
}