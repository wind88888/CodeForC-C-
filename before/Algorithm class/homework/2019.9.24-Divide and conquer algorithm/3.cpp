#include<iostream>
using namespace std;
#define row 8
#define col 3

void merge_sort(int L,int R,float a[],float c[]);

float B[row][col]={1,5,11,2,7,6,3,9,13,12,16,7,14,25,3,19,22,18,23,29,13,24,28,4};
//行为各个建筑物，列为一个建筑物的三个坐标参数
int main()
{
    int i,j,k=0;
    float a[row*(col-1)];//a总共需要存放前两列的数据
    for(i=0;i<row;i++)//将高度归化为小数以便后面根据横坐标排序，不受高度影响
    {
        for(j=0;j<col-1;j++)
        {
            a[k]=B[i][j]+B[i][col-1]/100;
            k++;
        }
    }
    for(i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    float c[k];
    merge_sort(0,k-1,a,c);//归并排序
    for(i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    system("pause");
    return 0;
}
void merge_sort(int L,int R,float a[],float c[])
{
    int q,w,e;
    if(L>=R)
        return;
    int mid=(L+R)/2;
    merge_sort(L,mid,a,c);
    merge_sort(mid+1,R,a,c);
    for(q=L;q<=R;q++)
        c[q]=a[q];
    q=L,w=mid+1;
    for(e=L;e<=R;e++) 
    {
        if(q<=mid&&((w>R)||a[q]<a[w]))
        {
            a[e]=c[q++];
        }   
        else
        {
            a[e]=c[w++]; 
        }
    }   
}