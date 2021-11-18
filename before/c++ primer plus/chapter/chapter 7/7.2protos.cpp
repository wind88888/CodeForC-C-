#include <iostream>

void cheers(int);
double cube(double x);

int main()
{
    cheers(5);
    std::cout << "Give me a number: ";
    double side;
    std::cin >> side;
    double volume = cube(side);
    std::cout << "A" << side << "-foot cube has a volume of";
    std::cout << volume << "cubic feet.\n";
    cheers(cube(2));

    system("pause");
    return 0;
}

void cheers(int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
        cout << "Cheers!";
    cout << endl;
}

double cube(double x)
{
    return x*x*x;
}