#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Account {
    double balance;
};

void showMenu();
void displayBalance(Account& account);
void deposit(Account& account, double amount);
void withdraw(Account& account, double amount);

#endif