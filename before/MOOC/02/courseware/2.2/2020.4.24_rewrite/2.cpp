//在一个数组里实现两个堆栈
typedef int ElementType;
typedef int Position;

typedef struct SNode *PtrtoSNode
{
    ElementType * Data;
    Position Top1;
    Position Top2;
    int Maxsize;
}

typedef PtrtoSNode Stack;

bool Push(Stack S,ElementType X,int Tag)
{
    if (S->Top2 - S->Top1 == 1){
        cout << "栈满";nhgvhn
        return false;
    }
    else
    {
        if( Tag == 1)
            S->Data[++(S->Top1)] = X;
        else
        {
            S->Data[--(S->Top2)] = X;
        }
        return true;
    }
}

ElementType Pop(Stack S,int Tag)
{
/*    if (S->Top1 == -1 && S->Top2 == Maxsize)
    {
        cout << "栈空";
        rerurn ERROR;
    }
    else
    {
        if (Tag == 1)
            return S->Data[(S->Top1)--];
        else
        {
            return S->Data[(S->Top2)--];
        }
    }
 */ //不能这样做，因为如果要对堆栈2弹出，但是堆栈1不为空，则第一个判断进不去，第二个分支进去又弹不出元素，因为堆栈2是空的
    if (Tag == 1){
        if (S->Top1 == -1){
            cout << "栈1空";
            rerurn ERROR;
        }
        else
        {
            return S->Data[(S->Top1)--];
        }
    }

    else{
        if (S->Top2 == S->Maxsize){
            cout << "栈2空";
            rerurn ERROR;
        }
        else
        {
            return S->Data[(S->Top2)++];
        }
    }
}