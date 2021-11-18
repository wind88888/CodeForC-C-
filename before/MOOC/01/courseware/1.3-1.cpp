//最大子列和问题
//算法1：确定起始点和终点，中间点穷举
//复杂度为N^3
#include<iostream>
using namespace std;
#define INF 0X3F3F3F3F

int A[10000];

int MaxSubseqSuml(int A[],int n)
{
    int i,j,k;//maxsum初始值设为负无穷，不能设为0，以防序列都为负数
    int thissum,maxsum=-INF;//别忘记赋初值
    for(i=0;i<n;i++)//i是子列左端位置
        for(j=i;j<n;j++){//j是子列右端位置
            thissum=0;//在每新一轮的子列和计算开始时初始化为0
            for(k=i;k<=j;k++)//k是子列
            {
                thissum+=A[k];//累加子列
                if(thissum>maxsum)//如果刚得到的这个子列和更大
                    maxsum=thissum;//则更新结果
            }
        }
    return maxsum;
}

int main()
{
    int n;
    int i;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];

    cout<<MaxSubseqSuml(A,n)<<endl;
    
    system("pause");
    return 0;
}