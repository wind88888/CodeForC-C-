#include<iostream>
#include<cmath>
using namespace std;
#define row 8
#define col 3

void merge_sort(int L,int R,double a[],double c[]);
double outline(int L,int R,double a[]);

double B[row][col]={1,5,11,2,7,6,3,9,13,12,16,7,14,25,3,19,22,18,23,29,13,24,28,4};
//行为各个建筑物，列为一个建筑物的三个坐标参数
int main()
{
    int i,j,k=0;
    double a[row*(col-1)];//a总共需要存放前两列的数据
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
    double c[k];//归并排序的中间数组

    merge_sort(0,k-1,a,c);
    for(i=0;i<k;i++)
         cout<<a[i]<<" ";
    cout<<endl;

    outline(0,k-1,a);//寻找轮廓点
    for(i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    for(i=0;i<k;i++)
    {
        if(a[i]>1)
            cout<<(int)(a[i])<<","<<((a[i]-(int)(a[i]))*100)<<" "; 
    }
    cout<<endl;

    system("pause");
    return 0;
}
void merge_sort(int L,int R,double a[],double c[])
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

double outline(int L,int R,double a[])
{
    int i,j,p,num,flag=0,flag1=45645,q,o;//num用来记录相同高度的点的标号;flag1用来记录高度要变成0的元素的标号；flag记录相同高度之间有多少个小于端点的数
    double min_high=2342;
    for(i=L;i<=R;i++)//整个数组的循环
    {
        if(a[i]>=1&&i!=flag1)//整数或者小数已经置0的元素不再考虑
        {
            for(j=i+1;j<=R;j++)//寻找数组剩余元素，与它相等的或者比他小或大的
            {
                if(abs((a[j]-(int)(a[j]))-(a[i]-(int)(a[i])))<1.0e-6)//在后面寻找到了高度相等的元素
                {
                    num=j;//跟a[i]高度相等元素的标号
                    for(p=i+1;p<num;p++)
                    {
                        if((a[p]-(int)(a[p]))<(a[i]-(int)(a[i])))
                        {   
                            flag++;
                            a[p]=a[p]-(int)(a[p]);//有比端点小的都置0；
                        }
                    }
                    if(abs((a[i]-(int)(a[i]))-(a[num]-(int)(a[num])))<1.0e-6&&i+1==num)//高度相等的两个元素中间没有元素
                    {
                        for(q=i-1;q>=L;q--)//先往左边寻找小于1的数(即找高度最小值，它肯定将连续的两个元素包含在内)
                        {
                            if(a[q]<1)
                            {
                                for(o=num+1;o<=R;o++)
                                {
                                    if(((a[o]-(int)(a[o]))-a[q])<1.0e-6)
                                    {
                                        min_high=a[q];
                                        break;
                                    }
                                }
                            }
                            if(min_high!=2342)
                                break;
                        }
                        a[num]=(int)a[num]+min_high;
                        flag1=num;
                    } 
                    if(flag==num-i-1&&flag>1)//如果两个相同元素之间的元素都比他们小，则右端点小数置0   
                    {
                        a[num]=(int)a[num];
                        flag1=num;
                    }
                    if(flag==num-i-1&&flag==1)////如果两个相同元素之间的元素都比他们小，且只有一个，则右端点小数置为中间元素的小数
                    {
                        a[num]=(int)a[num]+a[num-1];
                        flag1=num;
                    }
                    flag=0;
                    break;//找到右端就不需要在往右找，开启下一段的寻找。
                }
            }
        }
    }
}