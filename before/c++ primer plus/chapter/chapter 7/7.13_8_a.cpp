#include <iostream>
using namespace std;
const int Seasons = 4;
const char * Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};//error

void fill(double * Pa);
void show(double da[]);

int main()
{
    double expenses[Seasons];
    fill(expenses);
    show(expenses);

    system("pause");
    return 0;
}

void fill(double * Pa)
{
    for (int i = 0; i < Seasons; i++){
        cout << "Enter " << *(Snames + i) << "expenses: ";
        cin >> *(Pa++);
    }
}
void show(double da[])
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << *(Snames + i) << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl; 
}
