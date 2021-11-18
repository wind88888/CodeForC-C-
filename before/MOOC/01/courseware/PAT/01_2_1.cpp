//算法2输出最大子序列和，序列首尾值
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f

int A[10000];

int main()
{
    int n,i,j;
    int start[10000];
    int end[10000];
    int k=0;
    int end1,start1;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];

    int thissum,maxsum=-INF;//maxsum初始值设为负无穷，不能设为0，以防序列都为负数
    for(i=0;i<n;i++)//i是子列左端位置
    {
        thissum=0;//thissum是从A[i]到A[j]的子列和
        for(j=i;j<n;j++)//j是子列右端位置
        {
            thissum+=A[j];
            //对于相同的i,不同的j,只要在j-1次循环的基础上累加1项即可
            if(thissum>maxsum)
            {//如果刚得到的这个子列和更大
                maxsum=thissum;//则更新结果
                end[k]=j;
                start[k]=i;
                k++;
            }
        }
    }

    if(maxsum<0)
    {
        maxsum=0;
        end1=n-1;
        start1=0;
    }
    else if(maxsum>=0)//序列只有0和负数，属于正常情况，正常计算
    {
        end1=end[k-1];
        start1=start[k-1];
    }
    cout<<maxsum<<' '<<A[start1]<<' '<<A[end1]<<endl;

    system("pause");
    return 0;
}