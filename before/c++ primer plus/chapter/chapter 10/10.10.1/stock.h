#ifndef STOCK_H_
#define STOCK_H_

class BankAccount{
private:
    char name[40];
    char acctnum[25];
    double balance;
public:
    BankAccount();
    BankAccount(const char * client, const char * num, double balance = 0.0);
    void show() const;
    void deposit(double cash);
    void withdraw(double cash);
};

#endif