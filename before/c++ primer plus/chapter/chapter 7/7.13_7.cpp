// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;

// function prototypes
double * fill_array(double * begin, double * end);
void show_array(const double * begin, const double * end);  // don't change data
void revalue(const double r, double * begin, const double * end);

int main()
{
    using namespace std;
    double properties[Max];

    const double * end = fill_array(properties, properties + Max);
    show_array(properties, end);

    cout << "Enter revaluation factor: ";
    double factor;
    while (!(cin >> factor))    // bad input
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Bad input; Please enter a number: ";
    }
    revalue(factor, properties, end);
    show_array(properties, end);

    cout << "Done.\n";

    system("pause");
    return 0;
}

double * fill_array(double * begin, double * end)
{
    using namespace std;
    double * temp;
    int i = 0;
    for (temp = begin; temp != end; temp++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> (*temp);
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated.\n";
           break;
        }
        else if ((*temp) < 0)     // signal to terminate
            break;
        i++;
    }
    return end;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double * begin, const double * end)
{
    using namespace std;
    const double * temp;
    int i = 0;
    for (temp = begin; temp != end; temp++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << (*temp) << endl;
        i++;
    }
}

// multiplies each element of ar[] by r
void revalue(const double r, double * begin, const double * end)
{
    using namespace std;
    double * temp;
    for (temp = begin; temp != end; temp++)
    {
        (*temp) *= r;
    }
}