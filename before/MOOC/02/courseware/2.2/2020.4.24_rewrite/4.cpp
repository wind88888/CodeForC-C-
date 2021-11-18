//堆栈应用：表达式求值
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100 //操作数序列可能的最大长度
#define INF 1e9  //代表正无穷

typedef double ElementType;//将堆栈的元素类型具体化
//类型一次对应运算数，运算符，字符串结尾
typedef enum {num, opr, end} Type;

//顺序堆栈实现
typedef int Position;

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
//新代码
Type GetOp(char * Expr, int * start)