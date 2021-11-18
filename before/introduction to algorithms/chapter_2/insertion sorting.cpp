#include<iostream>
using namespace std;

int main()

{
    int i,n,j,key;
    cout<<"请输入要对多少个数排序"<<endl;
    cin>>n;
    int a[n];
    cout<<"请连续输入"<<n<<"个数"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(j=1;j<n;j++)
    {
        key=a[j];
        i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    system("pause");
    return 0;
}