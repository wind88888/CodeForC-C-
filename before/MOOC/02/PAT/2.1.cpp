List Merge( List L1, List L2 )
{
    List pa,pb,pc,L;
    L = (List)malloc(sizeof(struct Node));

    pa = L1->Next;
    pb = L2->Next;
    pc = L;

    while (pa && pb){
        if (pa->Data <= pb->Data){
            pc->Next = pa;
            pc = pc->Next;
            pa = pa->Next;
        }
        else{
            pc->Next = pb;
            pc = pc->Next;
            pb = pb->Next;
        }
    }

    if (pa)
        pc->Next = pa;
    else
        pc->Next = pb;

    L1->Next = NULL;
    L2->Next = NULL;

    return L;
}