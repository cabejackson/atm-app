#include <iostream>
#include "atm.h"
using namespace std;

ATM::ATM(BankAccount& account) : account(account) {}

void ATM::run(){
    int menuOption;

    do {
        showMenu();
        cout << "Please choose an option (1, 2, 3, 4): ";
        cin >> menuOption;

        switch(menuOption) {
            case 1:
                displayBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
        };
    } while(menuOption != 4);
}

double ATM::getUserInput() {
    double amount;
    cout << "Enter amount: $";
    cin >> amount;
    return amount;
}

void ATM::showMenu() {
    cout << " --------Menu---------" << endl;
    cout << " 1. Check balance " << endl;
    cout << " 2. Deposit " << endl;
    cout << " 3. Withdraw " << endl;
    cout << " 4. Exit " << endl;
    cout << " ---------------------" << endl;
}

void ATM::displayBalance(){
    cout << "Balance is: $" << account.getBalance() << endl;
}

void ATM::deposit() {
    double amount = getUserInput();
    account.deposit(amount);
    displayBalance();
}

void ATM::withdraw() {
    double amount = getUserInput();
    account.withdraw(amount);
    displayBalance();
}