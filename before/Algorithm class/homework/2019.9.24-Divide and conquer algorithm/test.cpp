#include<iostream>
using namespace std;

int main()
{
    double a=2.06,b=9.13,c=9.0;

    a=a-(int)(a);
    cout<<a<<endl;

    b=(int)b+0/10;
    cout<<b<<endl;

    cout<<c<<endl;

    cout<<1e-2<<endl<<1.0e-2<<endl;
    
    system("pause");
    return 0;
}