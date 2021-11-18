#include <iostream>
using namespace std;
int main()
{
    int a,x;
    int b[100005];
    long long d = 0;
    cin>>a>>x;
    for(int i=0;i<x;i++)
    {
        d += (x-i)*a;
        b[i]=d%10;
        d/=10;
    }
    if(d)cout<<d;//如果现有最高位加完，d还不为0的话，那就有更高位需要数值
    //如果没有这句话，那么9+99+999等于107，而不是1107
    for(int i=x-1;i>=0;i--)
        cout<<b[i];
    if(x==0)cout<<0;

    system("pause");
    return 0;
}