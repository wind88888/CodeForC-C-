#include <iostream>
using namespace std;
long double probability(unsigned nums, unsigned picks);

int main()
{
    double total1,choices1;
    double total2,choices2;

    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed:\n";
    while ((cin >> total1 >> choices1 >> total2 >> choices2) && choices1 <= total1 && choices2 <= total2 && total2 < total1){
        cout << "You have one chance in ";
        cout << 1.0 / (probability(total1,choices1) * probability(total2,choices2));
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";

    system("pause");
    return 0;
}

long double probability(unsigned number, unsigned picks)
{
    long double result = 1.0;
    long double n = 0;
    unsigned p;
    for (n = number, p = picks; p > 0; n--, p--)
    {
        result = result * n / p;
    }
    return result;
}