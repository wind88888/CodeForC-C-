#include<iostream>
using namespace std;

double mediam(int X[],int start_x,int end_x,int Y[],int start_y,int end_y);

int main()
{
    int X[]={1,4,6,10,22,43,44};
    int Y[]={2,9,14,23,42,89,99};
    int n;
    double value;
    n=sizeof(X)/sizeof(X[0]);
    value=mediam(X,0,n-1,Y,0,n-1);
    cout<<value<<endl;
    system("pause");
    return 0;
}
double mediam(int X[],int start_x,int end_x,int Y[],int start_y,int end_y)
{
    int a,b;
    if(end_x==start_x)//当各序列只剩一个值时，即找到了中位数。放在整体函数的前部
            return (double)(X[start_x]+Y[start_y])/2;
    a=X[(end_x+start_x)/2];
    b=Y[(end_y+start_y)/2];
    if(a==b)
          return a; 
    if(a<b)
    {
        mediam(X,(end_x+start_x)/2,end_x,Y,start_y,(end_y+start_y)/2);
    }
    else//a>b
    {
        mediam(X,start_x,(end_x+start_x)/2,Y,(end_y+start_y)/2,end_y);
    }
}
