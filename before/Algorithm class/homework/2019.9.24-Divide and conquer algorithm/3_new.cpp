#include<iostream>
using namespace std;
#define row 8
#define col 3

void merge_sort(int L,int R,float a[],float c[]);
float outline(int L,int R,float a[]);

float B[row][col]={1,5,11,2,7,6,3,9,13,12,16,7,14,25,3,19,22,18,23,29,13,24,28,4};
//行为各个建筑物，列为一个建筑物的三个坐标参数

int main()
{
    int i,j,k=0;
    float a[row*(col-1)];//a总共需要存放前两列的数据
    for(i=0;i<row;i++)//将高度归化为小数以便后面根据横坐标排序，不受高度影响
    {
        for(j=0;j<col-1;j++)
        {
            a[k]=B[i][j]+B[i][col-1]/100;//归一化后的数组
            k++;
        }
    }
    for(i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    float c[k];//归并排序的中间数组

    merge_sort(0,k-1,a,c);
    for(i=0;i<k;i++)
         cout<<a[i]<<" ";
    cout<<endl;

    outline(0,k-1,a);//寻找轮廓点

    system("pause");
    return 0;
}
void merge_sort(int L,int R,float a[],float c[])
{
    int i,j,k;
    if(L>=R)
        return;
    int mid=(L+R)/2;//求得中间元素序号
    merge_sort(L,mid,a,c);//求解左问题
    merge_sort(mid+1,R,a,c);//求解右问题
    for(i=L;i<=R;i++)//将要排序的元素赋值给备用数组
        c[i]=a[i];
    i=L,j=mid+1;//归并两部分分别从最左边开始扫描比较
    for(k=L;k<=R;k++)//归并排序 
    {
        if(i<=mid&&((j>R)||c[i]<c[j]))//左问题未到边界，右问题未超边界。取较小元素
        {
            a[k]=c[i++];
        }   
        else
        {
            a[k]=c[j++]; 
        }
    }   
}

float outline(int L,int R,float a[])
{
    int i,j,p,num,flag=0,num1;//num用来记录相同高度的点的标号;num1用来记录中间高点的标号
    for(i=L;i<=R;i++)//整个数组的循环
    {
        if(a[i]>=1)//已经置0的元素不再考虑
        {
            for(j=L+1;j<=R;j++)//寻找数组剩余元素，与它相等的或者比他小或大的
            {
                if(a[j]=a[i])
                {
                    num=j;//跟a[i]相等元素的标号
                    if(num-i>2)//中间多于两个元素
                    {
                        for(p=i+1;p<num;p++)
                        {
                            if(a[p]<a[i])
                            {
                                a[p]=a[p]-(int)(a[p]);//有比端点小的都置0；
                                // flag++;//中间有比端点大的数
                            }
                        }
                        if(flag==0)//中间没有比端点大的数，中间的数都取0(整数部分)，右端点小数置0
                        {
                            for(p=i+1;p<j;p++)
                            {
                                a[p]=a[p]-(int)(a[p]);//整数部分置0==取消这个坐标
                            }
                            a[j]=(int)(a[j]);//右端点小数为0
                        }
                        if(flag==1)//中间有一个比端点大的数，前该点和左端点之外的取0
                        {
                            a[p-1]=a[p-1]-(int)(a[p-1]);
                            a[j]=a[j]-(int)(a[j]);
                        }
                        if(flag>1)//大于端点的数多于1个，则取消两个端点。此时取消左端点，因为右端点已经在flag=1时取消了
                        {
                            a[i]=a[i]-(int)(a[i]);
                        }
                    }
                }    
            }
        }
    }
}