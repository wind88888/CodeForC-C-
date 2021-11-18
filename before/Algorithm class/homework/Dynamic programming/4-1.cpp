//动态规划第一题
//自底向上
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
int a[120],sum[120];
int f[120][120];
int main()
{
    int n=5,k=2;
    sum[0]=0;
    
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        printf("%d  ",a[i]);
        sum[i]=sum[i-1]+a[i];
    }
 
    memset(f,0,sizeof(f));

    for(int i=1;i<=n;i++)  f[i][0]=sum[i];
 
 	int t=k-1;//防止计算不需要的，比如f(5,2),就不需要计算所有n小于5的乘号数为2的f了 
 	int temp=k;//记录初始乘号个数 
 	
    for(int i=2;i<=n;i++)//i个数 
    {
      //int t=min(i-1,k);//当只有k个数时，不需要k个乘号，k-1个就够了 
        if(i==n)
      	  	t=temp; 
      for(int j=1;j<=t;j++)//需要添加j个乘号，j应该小于t(乘号的个数) 
      {                    //因为它已经在累加和的前面放了1个乘号，前面不可能再有t个乘号了 
          for(int k=1;k<=i;k++)  
          {
              int s=sum[i]-sum[k];
              f[i][j]=max(f[k][j-1]*s,f[i][j]);
          }
      }
    }
 
    printf("\n%d\n",f[n][k]);
    system("pause");
    return 0;
}