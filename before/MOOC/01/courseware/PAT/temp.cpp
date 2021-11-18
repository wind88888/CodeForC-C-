#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0X3F3F3F3F

int main()
{
    int i;
    int maxsum=-INF,thissum=0;
    int n;
    int a[10000];
    int start=INF,end=-INF;
    int start_temp=0;

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        thissum+=a[i];
        if(thissum>maxsum)//最大子序列和的开始与结束就是在更新最大值的开始与结束
        {
            maxsum=thissum;
            end=i;
            start=start_temp;//只有end更新了，才代表前面变化的start可用

        }
        if(thissum<0)
        {
            thissum=0;
            start_temp=i+1;//当子序列和小于0要舍弃时，start从下一位置开始计数
            //end不更新，start也不跟新，要同步
            //start=i+1;
        }
    }

    if(maxsum<0)
    {
        maxsum=0;
        start=0;
        end=n-1;
    }

    cout<<maxsum<<' '<<a[start]<<' '<<a[end]<<endl;

    system("pause");
    return 0;
}