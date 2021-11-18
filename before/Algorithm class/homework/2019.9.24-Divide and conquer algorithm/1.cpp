#include<iostream>
using namespace std;

double median(int X[],int start_x,int end_x,int Y[],int start_y,int end_y);

int main()
{
    int X[]={1,4,6,10,23,43,44};
    int Y[]={2,9,14,22,42,89,99};
    int n;
    double value;
    n=sizeof(X)/sizeof(X[0]);
    value=median(X,0,n-1,Y,0,n-1);
    cout<<value<<endl;
    system("pause");
    return 0;
}
double median(int X[],int start_x,int end_x,int Y[],int start_y,int end_y)
{
    int a,b;//中位数下标
    if(start_x==end_x)//只剩一位
    {
        if(X[start_x]>Y[start_y]&&X[start_x]>Y[start_y+1])//运算的两个数都在X数组
        {
            X[start_x]=Y[start_y+1];
        }
        else if(Y[start_y]>X[start_x]&&Y[start_y]>X[start_x+1])//运算的两个数都在Y数组
        {
            Y[start_y]=X[start_x+1];
        }
        return (double)(X[start_x]+Y[start_y])/2;//计算中位数
    }
    a=(end_x+start_x)/2;
    b=(end_y+start_y)/2;

    if((start_x+end_x)%2==0)//奇数个元素
    {
        if(X[a]<Y[b])
        {
            median(X,a,end_x,Y,start_y,b);
        }
        else//a>b
        {
            median(X,start_x,a,Y,b,end_y);
        }
    }
    else//偶数个元素
    {//较小的元素，起始位加一
        if(X[a]<Y[b])
        {
            median(X,a+1,end_x,Y,start_y,b);
        }
        else//a>b
        {
            median(X,start_x,a,Y,b+1,end_y);
        }
    }
}