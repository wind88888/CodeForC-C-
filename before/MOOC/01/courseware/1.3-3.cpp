//最大子列和问题
//算法3：分治算法
//顺序累加，如果thissum小于0，则对后面的元素的最大子列和没有贡献
//此时置0，重新计算子列和
//复杂度为NlogN
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f

int A[10000];

int Max3(int a,int b,int c)//返回3个整数中的最大值
{
    return a>b ? a>c ? a : c : b>c ? b : c;
}

int DivideAndConquer( int List[], int left, int right )//分治法求List[left]到List[right]的最大子列和
{
    int maxleftsum,maxrightsum;//存放左右子问题的解
    int maxleftbordersum,maxrightbordersum;//存放跨分界线的结果
    int leftbordersum,rightbordersum;
    int center,i;

    if(left==right)//递归的终止条件，子列只有1个数字
    {
        if(List[left]>0) return List[left];
        else return 0;
    }
    //下面是"分"的过程
    maxleftsum=-INF;maxrightsum=-INF;
    center=(left+right)/2;//找到中分点
    maxleftsum=DivideAndConquer(List,left,center);
    maxrightsum=DivideAndConquer(List,center+1,right);
    //下面求跨分界线的最大子列和
    maxleftbordersum=-INF;leftbordersum=0;
    for(i=center;i>=left;i--)//从中线向左扫描
    {
        leftbordersum+=List[i];
        if(leftbordersum>maxleftbordersum)
            maxleftbordersum=leftbordersum;
        // if(leftbordersum<0) 
        //     leftbordersum=0;//不能置0,因为是从分界线向左累加，有负数还是得累加，取大值就行
    }//左边扫描结束

    maxrightbordersum=-INF;rightbordersum=0;
    for(i=center+1;i<=right;i++)//从中线向右扫描
    {
        rightbordersum+=List[i];
        if(rightbordersum>maxrightbordersum)
            maxrightbordersum=rightbordersum;
        // if(rightbordersum<0) 
        //     rightbordersum=0;
    }//右边扫描结束
    //下面返回"治"的结果
    return Max3( maxleftsum, maxrightsum, maxleftbordersum + maxrightbordersum );
}

int MaxSubseqSum3( int List[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    
    cout<<MaxSubseqSum3(A,n);

    system("pause");
    return 0;
}