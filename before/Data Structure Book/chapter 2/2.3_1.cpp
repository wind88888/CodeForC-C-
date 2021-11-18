#include<iostream>
#include <cmath>

long add(int a, long n);

int main()
{
    int a;
    long n;

    std::cin >> a >> n;

    std::cout << add(a, n) << std::endl;

    system("pause");
    return 0;
}

long add(int a, long n)
{
    long sum=0;

    if (n == 1)
        return a;
        
    for (; n>0; n--)
        sum += pow(10, n-1) * a;
        
    return sum + add(a, n-1);
}