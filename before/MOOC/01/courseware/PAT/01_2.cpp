//在线算法输出最大子序列和，序列首尾值
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
    int start_temp=0;//因为start_temp不给初值为任意数，序列第0位需要给start.
                    //或者static start_temp;
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
            //即end和start需要在同一个条件语句块中，所以不能在更新thissum出更改最终要输出的start值
            //thissum<0意味着新的子序列在索引i下一个开始，开头位置需要变化，但不一定要用，因为start和end要同步
        }
        if(thissum<0)//不能写成else if
        {
            thissum=0;
            start_temp=i+1;//当子序列和小于0要舍弃时，start从下一位置开始计数
            //end不更新，start也不跟新，要同步
            //start=i+1;
        }
    }
/*不能初始化maxsum=0，因为如果序列是0和负数，他其实是有最大子序列和的 就是0
    if(!maxsum)
        cout<<maxsum<<" "<<a[0]<<" "<<a[n-1]<<endl;
    else
    {
        cout<<maxsum<<" "<<a[start]<<" "<<a[end]<<endl;
    }
*/
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



#include<iostream>
using namespace std;

#define MAXSIZE 10000
#define INF 0X3F3F3F3F 

int PAT2(int a[], int n);

int main()
{
    int a[MAXSIZE];
    int n;

    cin>>n;

    for (int i=0;i<n;i++)
        cin>>a[i];

    PAT2(a, n);
      
    system("pause");
    return 0;
}

int PAT2(int a[], int n)
{
    int sum=0;
    int maxsum=-INF;
    int start=0,end;
    int starttemp;

    for (int i=0; i<n; i++){
        sum+=a[i];
        if (sum>maxsum){
            maxsum=sum;
            end=i;
            start=starttemp;
        }
        else if (sum<0){
            sum=0;
            starttemp=i+1;
        }
    }

    if(maxsum<0)
    {
        maxsum=0;
        start=0;
        end=n-1;
    }

    cout<<maxsum<<' '<<a[start]<<' '<<a[end]<<endl;
}