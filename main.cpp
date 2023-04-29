#include <iostream>
using namespace std;

void showMenu() {
    cout << " --------Menu---------" << endl;
    cout << " 1. Check balance " << endl;
    cout << " 2. Deposit " << endl;
    cout << " 3. Withdraw " << endl;
    cout << " ---------------------" << endl;
};

int main() {

    // functionality - check balance, deposit, withdraw, show menu

    int option;
    double balance = 500;
    double depositAmount;
    double withdrawAmount;

    showMenu();
    cout << "Please choose an option (1, 2, 3): ";
    cin >> option;

    switch(option) {
        case 1:
            cout << "Balance is: $" << balance << endl;
            break;
        case 2:
            cout << "Deposit amount: $";
            cin >> depositAmount;
            if (depositAmount > 0) { 
            balance += depositAmount;
            } else {
                cout << "Deposit must be greater than 0" << endl;
            }
            cout << "The Balance is now: $" << balance << endl;
            break;
        case 3:
            cout << "How much would you like to withdraw?: $";
            cin >> withdrawAmount;
            if (withdrawAmount <= balance) {
                balance -= withdrawAmount;
                cout << "The Balance is now: $" << balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
            break;
    };

    return 0;
}