#include <iostream>
using namespace std;

long long factorial(int n);

int main()
{
    int n;

    cout << "Please input num(q is to quit)" << endl;
    while (cin >> n){
        cout << factorial(n) << endl;
        cout << "Please input next num(q is to quit)" << endl;  
    }

    system("pause");
    return 0;
}

long long factorial(int n)
{
    long result;

    if (n == 0)
        return 1;
    else
        result = n * factorial(n-1);

    return result;
}