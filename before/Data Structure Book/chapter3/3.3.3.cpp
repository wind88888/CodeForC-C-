#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

#define MAXOP 100
#define INF 0X3F3F3F3F
typedef double ElementType;

typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;

typedef enum {num, opr, end} Type;

Stack CreatStack(int MaxSize);
bool IsFull(Stack S);
bool IsEmpty(Stack S);
bool Push(Stack S, ElementType X);
ElementType Pop(Stack S);

Type GetOp(char *Expr, int *start, char *str);
ElementType PostfixExp(char *Expr);

int main()
{

}

Stack CreatStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(SNode));
    S->Data = (ElementType*)malloc(sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize-1);
}

bool IsEmpty(Stack S)
{
    return (S->Top == -1);
}

bool Push(Stack S, ElementType X)
{
    if (IsFull(S))
    {
        std::cout << "该堆栈已满"<<std::endl;
        return false;
    }
    else
    {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        std::cout << "该堆栈已空"<<std::endl;
        return -1;
    }
    else
    {
        return S->Data[(S->Top)--];
    }
}

Type GetOp(char *Expr, int *start, char *str)
{
    int i = 0;

    while ((str[0] = Expr[(*start)++]) == ' ');

    while (str[i] != ' ' && str[i] != '\0')
        str[++i] = Expr[(*start)++];
    
    if (i == 0) return end;
    else if (isdigit(str[0]) || isdigit(str[1]))
        return num;
    else
    {
        return opr;
    }
}

ElementType PostfixExp(char * Expr)
{
    Stack S;
    Type T;
    ElementType Op1,Op2;
    char str[MAXOP];
    int start = 0;

    S = CreatStack(MAXOP);

    Op1 = Op2 =0;
    while ((T = GetOp(Expr, &start, str)) != end)
    {
        if (T == num)
            Push(S, atof(str));
        else
        {
            if (!Is)
        }
        
    }
    
}