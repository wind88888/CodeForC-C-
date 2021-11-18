//д��������������ʽ�ڸ�����x����ֵ
//f(x)=a0+a1x+...+an-1xn-1+anxn
//f(x)=a0+x(a1+x(...(an-1+x(an))...))
#include <stdio.h>
#include<iostream>
#include <time.h>
#include <math.h>
using namespace std;
clock_t start,stop;
double duration;
#define MAXN 10//����ʽ���������������ʽ����+1
#define MAXK 1e7//���⺯������ظ����ô���
double f1(int n, double a[], double x);
double f2(int n, double a[], double x); 
/*C++�Ѻ���A��Ϊ�������ݸ����⺯��Bʱ��ʵ�����ǰѺ���A��Ϊָ�봫�ݸ�����ĺ���B������漰���˺���ָ�롣*/
/*https://www.cnblogs.com/jainszhang/p/10704514.html*/
void fclock(double (*f)(int n, double a[], double x));

int i;
double a[MAXN];//�洢����ʽ��ϵ��

int main()
{
    for(i=0;i<MAXN;i++)
        a[i]=(double)i;

    fclock(f1);
    fclock(f2);
    system("pause");
    return 0;
}

double f1(int n,double a[],double x)
{
    int i;
    double p=a[0];
    for(i=1;i<=n;i++)
        p+=(a[i]*pow(x,i));
    return p;
}
double f2(int n, double a[], double x)
{
    int i;
    double p=a[n];
    for (i=n;i>0;i--)
        p=a[i-1]+x*p;
    return p;
}
void fclock(double (*f)(int n, double a[], double x))
{
    start=clock();
    for(i=0;i<MAXK;i++)//�ظ����ú����Ի�ó�ֵ�ʼ�մ����
        f(MAXN-1,a,1.1);
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK/MAXK;
    printf("ticks = %f\n",(double)(stop-start));
    printf("duration= %6.2e\n",duration);
}