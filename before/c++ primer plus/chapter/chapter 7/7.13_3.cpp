#include <iostream>
using namespace std;

struct box
{
    char market[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_by_value(box aa);
void set_vol(box * bb);

int main()
{
    box mbox = {"xiaojianjian",1,2,3};
    show_by_value(mbox);
    set_vol(&mbox);
    show_by_value(mbox);

    system("pause");
    return 0;
}

void show_by_value(box aa)
{
    cout << "market = " << aa.market << endl;
    cout << "height = " << aa.height << endl;
    cout << "width = "  << aa.width  << endl;
    cout << "length = " << aa.length << endl;
    cout << "volume = " << aa.volume << endl;
}

void set_vol(box * bb)
{
    bb->volume = bb->height * bb->length * bb->width;
}

