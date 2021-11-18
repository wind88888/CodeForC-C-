#include<iostream>
using namespace std;

#define MAXSIZE 10
#define INF 0X3F3F3F3F 

int MaxSubseqsum1(int a[],int n);
int MaxSubseqsum2(int a[],int n);
int Max3(int A, int B, int C);
int DivideAndConquer(int a[], int left, int right);
int MaxSubseqsum3(int a[],int n);
int MaxSubseqsum4(int a[],int n);
int PAT2(int a[], int n);

int main()
{
    int a[MAXSIZE];
    int n;

    cin>>n;

    for (int i=0;i<n;i++)
        cin>>a[i];

    cout<<MaxSubseqsum1(a,n)<<endl;
    cout<<MaxSubseqsum2(a,n)<<endl;
    cout<<MaxSubseqsum3(a,n)<<endl;
    cout<<MaxSubseqsum4(a,n)<<endl;

    PAT2(a, n);
      
    system("pause");
    return 0;
}
//O(N^3)
int MaxSubseqsum1(int a[],int n)
{
    int sum=0;
    int maxvalue=-INF;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            sum=0;
            for (int k=i;k<=j;k++){
                sum+=a[k];
                if (sum>maxvalue)
                    maxvalue=sum;
            }
            }
        }
    return maxvalue;
}
//O(N^2)
int MaxSubseqsum2(int a[],int n)
{
    int maxvalue=-INF;
    int sum=0;
    for (int i=0;i<n;i++){
        sum=0;
        for (int j=i;j<n;j++){
            sum+=a[j];
            if(sum>maxvalue){
                maxvalue=sum;
            }
        }
    }
    return maxvalue;
}
//分治
int Max3(int A, int B, int C)
{
    return A>B ? A>C ? A : C : B>C ? B : C;
}

int DivideAndConquer(int a[], int left, int right)
{
    int maxleftsum,maxrightsum;
    int maxleftbordersum,maxrightbordersum;
    int leftbordersum,rightbordersum;
    int center;

    if (left==right){
        if (a[left]>0)
            return a[left];
        else
            return 0;
    }


    center=(left+right)/2;

    maxleftsum=DivideAndConquer(a,left,center);
    maxrightsum=DivideAndConquer(a,center+1,right);

    maxleftbordersum=0;
    leftbordersum=0;
    for(int i=center; i>=left; i--){
        leftbordersum+=a[i];
        if(leftbordersum>maxleftbordersum)
            maxleftbordersum=leftbordersum;
    }

    maxrightbordersum=0;
    rightbordersum=0;
    for(int i=center+1; i<=right; i++){
        rightbordersum+=a[i];
        if(rightbordersum>maxrightbordersum)
            maxrightbordersum=rightbordersum;
    }

    return Max3(maxleftsum,maxrightsum,maxleftbordersum+maxrightbordersum);
}

int MaxSubseqsum3(int a[],int n)
{
    return DivideAndConquer(a, 0, n-1);
}

int MaxSubseqsum4(int a[],int n)
{
    int sum=0;
    int maxsum=-INF;

    for(int i=0; i<n; i++){
        sum+=a[i];
        if(sum>maxsum)
            maxsum=sum;
        if(sum<0)
            sum=0;
    }
    return maxsum;
}

int PAT2(int a[], int n)
{
    int sum=0;
    int maxsum=-INF;
    int start,end;
    int starttemp=0;

    for (int i=0; i<n; i++){
        sum+=a[i];
        if (sum>maxsum){
            maxsum=sum;
            end=i;
            start=starttemp;
        }
        if (sum<0){
            sum=0;
            starttemp=i+1;
        }
    }

    if(maxsum<0)
    {
        maxsum=0;
        start=0;
        end=n-1;
    }

    cout<<maxsum<<' '<<a[start]<<' '<<a[end]<<endl;
}