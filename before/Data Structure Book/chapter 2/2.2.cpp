#include<iostream>

#define size 100

int a[size];

int main()
{
    int n, bit;
    int temp;
    int count=0;
    
    int index = n-1;//从最后一个元素开始
    int temp2 = a[index];
    int temp1;

    std::cin >> n >> bit;

    bit = bit % n;//m大于n

    for (int i=0; i<n; i++)
        std::cin >> a[i];
//总共要处理数据n次，从最后一个元素开始不停往前替换
    while (count <= n){
        if (index < bit)//索引小于bit,要左移到右半部分
        {
            temp1 = a[index-bit+n];
            a[index-bit+n] = temp2;
            index = index - bit + n;
            count++;
            temp2 = temp1;
        }
        else//索引大于bit,正常左移
        {
            temp1 = a[index-bit];
            a[index-bit] = temp2;
            index = index - bit;
            count++;
            temp2 = temp1;
        }
    } 

    for (int i=0; i<n; i++){
        if (i < n-1)
            std::cout << a[i] << " ";
        else 
            std::cout << a[i];
    }

    system("pause");
    return 0;
}