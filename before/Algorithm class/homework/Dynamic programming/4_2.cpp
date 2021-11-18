//动态规划第一题
//自下而上
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
int b[120],sum[120];


int ff(int i,int j)
{
    int s=0,temp=-100;
    if(j==0)//当k=0时 
	{
        temp=sum[i];
    } 
    else
    {
        for(int m=i;m>=2;m--)
        {
          int s=sum[i]-sum[m];
          temp=max(ff(m,j-1)*s,temp);           
        }
    
    }
    return temp;
}

int main()
{
    int n=5,k=2;//元素个数+乘号个数 
    sum[0]=0;//元素和的初始化 
    for(int h=1;h<=n;h++)
    {
        b[h]=h;//元素赋值 
        sum[h]=sum[h-1]+b[h];//计算各元素和 
    }
    
	printf("\n\nbiggest=%d\n",ff(n,k));//输出最后结果 
	
    system("pause");
    return 0;
}