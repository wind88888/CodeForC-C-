//最大子列和问题
//算法2：确定起始点，穷举终点
//复杂度为N^2
#include<iostream>
using namespace std;

int A[100000];
#define INF 0x3f3f3f3f

int MaxSubseqSuml(int A[],int n)
{
    int i,j;
    int thissum,maxsum=-INF;//maxsum初始值设为负无穷，不能设为0，以防序列都为负数
    for(i=0;i<n;i++)//i是子列左端位置
    {
        thissum=0;//thissum是从A[i]到A[j]的子列和
        for(j=i;j<n;j++)//j是子列右端位置
        {
            thissum+=A[j];
            //对于相同的i,不同的j,只要在j-1次循环的基础上累加1项即可
            if(thissum>maxsum)//如果刚得到的这个子列和更大
                maxsum=thissum;//则更新结果
        }
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