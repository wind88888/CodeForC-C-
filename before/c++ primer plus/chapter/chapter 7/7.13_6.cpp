#include <iostream>
using namespace std;


double Fill_array(double a[],int length);
void Show_array(double a[],int length);
void Reverse_array(double a[],int length);

int main()
{
    int length;
    int cnt;
    cout << "please input the nums of the array: ";
    cin >> length;

    double a[length];
    cnt = Fill_array(a,length);

    cout << "you input" << cnt << " numbers" << endl; 

    Show_array(a,length);

    Reverse_array(a,length);

    Show_array(a,length);

    system("pause");
    return 0;
}

double Fill_array(double a[],int length)
{
    int i = 0;
    cout << "Please input value of the array(q is to quit): " << endl;
    while (i <= length-1 && cin >> a[i])
        i++;
    
    return i+1;
}

void Show_array(double a[],int length)
{
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Reverse_array(double a[],int length)
{
    double tmp;
    for (int i = 0; i < length/2; i++){
        tmp = a[i];
        a[i] = a[length-1-i];
        a[length-1-i] = tmp;
    }
}