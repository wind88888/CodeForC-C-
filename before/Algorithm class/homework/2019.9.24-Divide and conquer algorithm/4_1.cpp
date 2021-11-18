#include<iostream> 
using namespace std;

int main()
{
	int i,j,n,max,min;
	cin>>n;
	int a[n+10],s[n+10];//原数组，和数组
	s[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];//求和
	}
	min=s[0];//设定初始最小值
	max=a[1];//设定初始最大值
	for(j=1;j<=n;j++)
	{
		if(s[j]<min)//存在更小的连续子数组和，则赋给min
		  min=s[j];
		if(s[j]-min>max)//存在更大的连续子数组和，则赋给max
		  max=s[j]-min;
	}
	cout<<max<<endl;
    system("pause");
    return 0;
}