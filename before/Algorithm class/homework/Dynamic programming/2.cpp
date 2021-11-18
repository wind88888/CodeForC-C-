//钢条切割 自顶向下
#include<iostream>
#include<algorithm>
using namespace std;

int p[]={0,1,5,8,9};
int r[1000];

int cut(int p[],int n,int r[])
{
    int temp,i;
    if(r[n]>=0)//r(n)计算过就不用再算了(存储)
        return r[n];
    if(n==0)//r(0)不用计算
        temp=0;
    else
    {
        temp=-7397428;
        for(i=1;i<=n;i++)
            temp=max(temp,p[i]+cut(p,n-i,r));
    }
    r[n]=temp;
    return temp;
}

int main()
{
    int n=sizeof(p)/sizeof(p[0])-1;
    int i;
    for(i=1;i<=n;i++)
    {
        r[i]=-8413849;
    }
    cout<<cut(p,n,r);

    system("pause");
    return 0;
}
