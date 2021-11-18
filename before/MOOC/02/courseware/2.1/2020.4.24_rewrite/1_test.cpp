//顺序存储的线性表
#define MAXSIZE 100
#define ERROR -2

typedef int Position;
typedef int ElementType ;

typedef struct Lnode *PtrtoLnode
{
    ElementType Data[MAXSIZE];
    Position Last;
};

typedef PtrtoLnode List;

//初始化
List MakeEmptyList()
{
    List L;
    L = (List)malloc(sizeof(struct Lnode));
    L->Last = -1;
    return L;
}

Position Find(List L, ElementType X)
{
    int i = 0;

    while (L->Data[i] != X && i <= L->Last){
        i++;
    }

    if (i > L->Last)
        return ERROR;
    else
    {
        return i;
    }
}
//i为位序，i>=1 && i<=n+1
bool Insert(List L,ElementType X,int i)
{
    Position j;

    if (L->Last == MAXSIZE-1)
    {
        cout << "表满";
        return false;
    }

    if (i < 1 || i > L->Last+2)
    {
        cout << "位序不合法";
        return false;
    }

    for (j = L->Last+1;j >= i;j--)//这里的j是数组坐标
    {
        L->Data[j] = L->Data[j-1];
    }

    L->Data[i-1] = X;
    L->Last++;
    return true;
}

//i为位序，i>=1 && i<=n
bool Delete(List L,Position i)
{
    Position j;
    if (i < 1 || i > L->Last+1)
    {
        cout << "位序不合法";
        return false;
    }
    for (j = i-1; j <= L->Last-1n; j++)
    {
        L->Data[j] = L->Data[j+1];
    }
    L->Last--;
    return true;
}
