//算法4 在线算法输出最大子列和
#include<iostream>
using namespace std;

int main()
{
    int i;
    int maxsum=0,thissum=0;
    int n;
    int a[100000];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        thissum+=a[i];
        if(thissum>maxsum)
            maxsum=thissum;
        if(thissum<0)
            thissum=0;
    }
    cout<<maxsum<<endl;
    system("pause");
    return 0;
}