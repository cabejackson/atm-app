#ifndef ATM_H
#define ATM_H

#include "bankaccount.h"

class ATM {
public:
    ATM(BankAccount& account);
    void run();

private:
    BankAccount& account;
    double getUserInput();
    void showMenu();
    void displayBalance();
    void deposit();
    void withdraw();
};

#endif