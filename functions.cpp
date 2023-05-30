#include <iostream>
#include "functions.h"
using namespace std;

void showMenu() {
    cout << " --------Menu---------" << endl;
    cout << " 1. Check balance " << endl;
    cout << " 2. Deposit " << endl;
    cout << " 3. Withdraw " << endl;
    cout << " 4. Exit " << endl;
    cout << " ---------------------" << endl;
};

void displayBalance(Account& account){
    cout << "Balance is: $" << account.balance << endl;
};

void deposit(Account& account, double amount) {
    if (amount > 0)
        account.balance += amount;
    else 
        cout << "Deposit must be greater than 0" << endl;
    displayBalance(account);
};

void withdraw(Account& account, double amount) {
    if (amount <= account.balance && amount > 0) {
        account.balance -= amount;
        displayBalance(account);
    } else if (amount <= 0)
        cout << "Withdraw must be greater than 0" << endl;
    else
        cout << "Insufficient funds." << endl;
};