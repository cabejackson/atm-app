#include <iostream>
using namespace std;

void showMenu() {
    cout << " --------Menu---------" << endl;
    cout << " 1. Check balance " << endl;
    cout << " 2. Deposit " << endl;
    cout << " 3. Withdraw " << endl;
    cout << " 4. Exit " << endl;
    cout << " ---------------------" << endl;
};

int main() {

    // functionality - check balance, deposit, withdraw, show menu

    int menuOption;
    double balance = 500;
    double depositAmount;
    double withdrawAmount;

    do {
        showMenu();
        cout << "Please choose an option (1, 2, 3, 4): ";
        cin >> menuOption;

        switch(menuOption) {
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
                cout << endl;
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
    } while(menuOption != 4);

    return 0;
}