#include <iostream>
using namespace std;
const int Seasons = 4;
const char * Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};//error

struct expenses
{
    double exp[Seasons];
};

void fill(expenses * Pa);
void show(expenses * da);
void show2(expenses ca);

int main()
{
    expenses EXP;//要创建个结构体实例
    fill(& EXP);
    show(& EXP);

    cout << endl;
    show2(EXP);

    system("pause");
    return 0;
}

void fill(expenses * Pa)
{
    for (int i = 0; i < Seasons; i++){
        cout << "Enter " << *(Snames + i) << "expenses: ";
        cin >> Pa->exp[i];
    }
}
void show(expenses * da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << *(Snames + i) << ": $" << da->exp[i] << endl;
        total += da->exp[i];
    }
    cout << "Total Expenses: $" << total << endl; 
}
void show2(expenses ca)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << *(Snames + i) << ": $" << ca.exp[i] << endl;
        total += ca.exp[i];
    }
    cout << "Total Expenses: $" << total << endl; 
}