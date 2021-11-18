//二分查找
//递归查找
#include<iostream>
#include<stdio.h>

using namespace std;

#define MAXSIZE 100

int X[MAXSIZE];

int binary_search(int temp,int bot,int top)
{
    int mid2;
    mid2=(top+bot)/2;
    if(top>=bot)
    {
        if(X[mid2]<temp)
        {
            binary_search(temp,mid2+1,top);
        }
        else if(X[mid2]>temp)
        {
            binary_search(temp,bot,mid2-1);
        }
        else
        {
            return mid2;
        }
    }   
}

int main()
{
    int value;
    int n;
    cin >> n;

    for (int i=1; i<=n; i++)//从位置1开始存放
        cin >> X[i];
    
    cin>>value;


    cout << binary_search(value,0,n-1)<<endl; 

    system("pause");
    return 0;
}