#include <iostream>
using namespace std;

void ave();
int main()
{
    ave();
    
    system("pause");
    return 0;
}

void ave()
{
    int sum_value;
    double x,y;

    cout << "请连续输入两个数(如果想退出输入0)：" << endl;
    cin >> x >> y;
    cout << endl;

    while (x != 0 && y != 0){

        sum_value = 2.0 * x * y / (x + y);
        cout << "调和平均数为:" << sum_value << endl;

        cin >> x >> y;
        cout << endl;
    }
}

/*
#include <iostream>
double h_mean(double x,double y);

int main(void)
{
    using namespace std;
    double x,y;

    cout << "Enter two numbers (a 0 terminates): ";
    while (cin >> x >> y && x * y != 0)
        cout << "harmonic mean of " << x << " and "
             << y << " = " << h_mean(x,y) << "\n";
    cout << "Bye\n";
    system("pause");
    return 0;
}

double h_mean(double x, double y)
{
    return 2.0 * x * y / (x + y);
}
*/