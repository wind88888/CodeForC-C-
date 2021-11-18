#include <iostream>
using namespace std;

void n_chars(char, int);

int main()
{
    int times;
    char ch;

    cout << "enter a character: ";
    cin>>ch;

    while (ch != 'q')
    {
        cout << "enter an integer: ";
        cin >> times;
        n_chars(ch,times);
        cout << "\nEnter another character or press the"
                "q-key to quit: ";
        cin >> ch;
    }
    cout << "the value of times is" << times << ".\n";
    cout << "Bye\n";

    system("pause");
    return 0;
}

void n_chars(char c, int n)
{
    while (n-- > 0)
    {
        cout << c;
    }
}