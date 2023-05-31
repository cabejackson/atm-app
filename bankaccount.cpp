#include <iostream>
#include "bankaccount.h"
using namespace std;

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

void BankAccount::deposit(double amount){
    if (amount > 0)
        balance += amount;
    else
        cout << "Deposit must be greater than 0" << endl;
}

void BankAccount::withdraw(double amount){
    if (amount <= balance && amount > 0)
        balance -= amount;
    else if (amount <= 0)
        cout << "Withdraw must be greater than 0" << endl;
    else
        cout << "Insufficient funds." << endl;
}
