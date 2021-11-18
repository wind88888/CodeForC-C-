// //二叉搜索树的动态查找
// typedef int ElementType;
// typedef struct TNode *Position;
// typedef Position BinTree;

// typedef struct TNode
// {
//     ElementType Data;
//     BinTree Left;
//     BinTree Right;
// }; 
// //二叉搜索树的递归查找
// Position2 Find(BinTree BST, ElementType X)
// {
//     if (!BST) return NULL;

//     if (X < BST->Data)
//         return Find(BST->Left, X);
//     else if(X > BST->Data)
//         return Find(BST->Right, X);
//     else
//         return BST;
// }

// //二叉搜索树的迭代查找
// Position2 Find(BinTree BST, ElementType X)
// {
//     while (BST){
//         if (X < BST->Data)
//             BST = BST->Left;
//         else if(X > BST->Data)
//             BST = BST->Right;
//         else
//             break;
//     }
//     return BST;
// }

// //二叉搜索树查找最小元素(递归)
// Position FindMin1(BinTree BST)
// {
//     if (BST){
//         if (BST->Left)
//             return FindMin1(BST->Left);
//         else
//             return BST;
//     }
//     else 
//         return NULL;
// }

// //二叉搜索树查找最小元素(迭代)
// Position FindMin2(BinTree BST)
// {
//     while (BST){
//         if (BST->Left)
//             BST = BST->Left;
//         else
//             break;
//     }
//     return BST;
// }

// //二叉搜索树查找最大元素(递归)
// Position FindMax1(BinTree BST)
// {
//     if (!BST) return NULL;
//     else if (!BST->Right)   return BST;
//     else return FindMax1(BST->Right);
// }

// //二叉搜索树查找最大元素(迭代)
// Position FindMax2(BinTree BST)
// {
//     if (BST){
//         while (BST->Right)
//             BST = BST->Right;
//     }
//     5f
//     return BST;
// }
