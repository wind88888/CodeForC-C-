//最大子列和问题
//算法4：在线算法
//顺序累加，如果thissum小于0，则对后面的元素的最大子列和没有贡献
//此时置0，重新计算子列和
//复杂度为N
#include<iostream>
using namespace std;

int A[10000];

int MaxSubseqSuml(int A[],int n)
{
    int i,thissum=0,maxsum=-427832;
    for(i=0;i<n;i++)
    {
        thissum+=A[i];//向右累加
        if(thissum>maxsum)
            maxsum=thissum;//发现更大和则更新当前结果
        if(thissum<0)//如果当前子列和为负
            thissum=0;//则不能使后面的部分和增大，抛弃之
    }
    return maxsum;
}

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    
    cout<<MaxSubseqSuml(A,n);

    system("pause");
    return 0;
}