#include <iostream>
#include "stock.h"
#include <string.h>

BankAccount::BankAccount()
{
    std::cout << "Default constructor called\n";
    name = "no name";
    acctnum = "no num";
    balance = 0.0;
}
BankAccount::BankAccount(const char * client, const char * num, double bal)
{
    strncpy(name, client, 39);
    name[39] = '\0';
    strncpy(acctnum, num, 24);
    acctnum[24] = '\0';
    balance = bal;
}

void BankAccount::show() const
{
    using std::cout;
    using std::endl;

    cout << "Client: " << name << endl;
    cout << "Accout Number: " << acctnum << endl;
    cout << "Balance: " << balance << endl;
}

void BankAccount::deposit(double cash)
{
    if (cash >= 0)
        balance += cash;
    else
    {
        std::cout << "Illegal transaction attempted";
    }
}
void BankAccount::withdraw(double cash)
{
    if (cash < 0)
        std::cout << "Illegal transaction attempted";
    else if (cash <= balance)
        balance -= cash;
    else
    {
        std::cout << "Request denied due to insufficient funds.\n";
    }   
}