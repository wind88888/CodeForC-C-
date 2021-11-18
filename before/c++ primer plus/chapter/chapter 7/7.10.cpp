#include <iostream>
using namespace std;

double calculate(double x, double y, double (*pf)(double, double));
double add(double x, double y);
double sub(double x, double y);
double mean(double x, double y);

int main()
{
    double (*pf[3])(double,double) = {add, sub, mean};
    char * op[3] = {"sum", "sub", "mean"};
    double a,b;
    cout << "Enter pairs of numbers (q to quit): ";
    int i;
    while (cin >> a >> b)
    {
        cout << calculate(a, b, add) << " = sum\n";
        cout << calculate(a, b, mean) << " = mean\n";
        for (i = 0; i < 3; i++){
            cout << calculate(a, b, pf[i]) << " = "
                 << op[i] << "\n";
        }
    }
    cout << "Done!\n";
    return 0;
}

double calculate(double x, double y, double (*pf)(double, double))
{
    return (*pf)(x, y);
}
double add(double x, double y)
{
    return x+y;
}
double sub(double x, double y)
{
    return x-y;
}
double mean(double x, double y)
{
    return (x+y) / 2.0;
}