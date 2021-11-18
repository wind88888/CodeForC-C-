#include <iostream>
#include "stock.h"
#include <string.h>
#include <math.h>

int main()
{
    BankAccount bird;
    BankAccount frog("Kermit", "croak32", 123.00);

    bird.show();
    frog.show();

    bird = BankAccount("Chipper", "peep8282", 214.00);
    bird.show();

    frog.deposit(20);
    frog.show();

    frog.withdraw(40000);
    frog.show();

    frog.withdraw(50);
    frog.show();

    system("pause");
    return 0;
}
