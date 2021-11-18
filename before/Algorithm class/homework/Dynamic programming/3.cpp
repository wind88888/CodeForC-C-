//动态规划作业第二题
//自上而下
#include<iostream>
#include<algorithm>
using namespace std;

int A[]={0,2,2,2,8,1,8,2,1};
int B=17;
int s[100];
int r[100];

int fun(int i,int n)
{
    int temp=7966676;
    int max2=-6867786;

    if(r[i]>=0)//fun(i,)计算过了就不用计算了
        return r[i];

    if (i>n)//fun(9,8)=0;
    {
        temp=0;
    }
    else
        for(int k=i;k<=n;k++){//k为断点
            for(int j=i;j<=k;j++)//计算A[i,k]的最大值
            {    
                // if(j==k&&(k==i))//计算A[j,j]的最大值
                //     max2=A[j];
                // else
                //     if(j>=n)
                //         break;
                //     else
                //         if(j==k)
                //             break;
                //         else
                max2=max(max2,A[j]);
            }
            int sum=s[k]-s[i-1];
            if(sum<=B)
                {
                    temp=min(temp,max2+fun(k+1,n));
                    r[i]=temp;//记录fun(i,)的值
                }
        }
    return temp;
}

int main()
{
    int n=sizeof(A)/sizeof(A[0])-1;
    int i;
    s[0]=0;
    for(i=1;i<=n;i++)
    {
        s[i]=s[i-1]+A[i];
    }
    for(i=0;i<12;i++)
        r[i]=-1;

    cout<<fun(1,n)<<endl;

    system("pause");
    return 0;
}