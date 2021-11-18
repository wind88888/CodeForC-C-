//二分查找
//循环查找
#include<iostream>
#include<stdio.h>

using namespace std;

#define MAXSIZE 100

int X[MAXSIZE];

int binary_search_2(int temp, int n)
{
    int mid2,top,bot,NoFound=-1;
    bot=1;
    top=n;

    while (top>=bot){
        mid2=(top+bot)/2;
        if (temp<X[mid2])      top=mid2-1;//调整右边界
        else if (temp>X[mid2]) bot=mid2+1;//调整左边界
        else return mid2; 
    } 
    return NoFound;  
}

int main()
{
    int value;
    int n;
    cin >> n;

    for (int i=1; i<=n; i++)//从位置1开始存放
        cin >> X[i];
    
    cin>>value;

    cout << binary_search_2(value,n)<<endl;

    system("pause");
    return 0;
}