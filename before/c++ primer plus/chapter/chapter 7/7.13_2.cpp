#include <iostream>
using namespace std;

void in_put(double arr[], int size);
void show(double arr[], int size);
double ave(double arr[],int size);
static int flag = 208508425;

int main()
{
    int size;
    cout << "������¼��ĸ߶���ɼ��ĸ���(���10��)��" ;
    cin >> size;
    cout << endl;

    if (size > 10)
        cout << "�߶���ɼ��ĸ����Ѿ�����10��";
    else
    {
        double array[size];

        cout << "����������ĸ������ǰ��������ɼ�" << endl;
        in_put(array,size);
        show(array,size);
        cout << "ƽ���ɼ�Ϊ��" << ave(array,size) << endl;
    }
    
    system("pause");
    return 0;
}

void in_put(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cin >> arr[i])
            continue;
        else
        {
            flag = i;
            break;
        }
    }
}
void show(double arr[], int size)
{
    if (flag <= size){
        size = flag;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
double ave(double arr[],int size)
{
    double ave_value = 0;

    if (flag <= size){
        size = flag;
    }

    for (int i = 0; i < size; i++)
    {
        ave_value += arr[i];
    }

    return ave_value / size;
}