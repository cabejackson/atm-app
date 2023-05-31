#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
public:
    double getBalance() const;
    void setBalance(double balance);
    void deposit(double amount);
    void withdraw(double amount);

private:
    double balance;
};

#endif