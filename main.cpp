#include <iostream>
using namespace std;

//global variables
double g_Balance = 500;

void showMenu() {
    cout << " --------Menu---------" << endl;
    cout << " 1. Check balance " << endl;
    cout << " 2. Deposit " << endl;
    cout << " 3. Withdraw " << endl;
    cout << " 4. Exit " << endl;
    cout << " ---------------------" << endl;
};

void checkBalance(){
    cout << "Balance is: $" << g_Balance << endl;
};

int main() {

    // functionality - check balance, deposit, withdraw, show menu

    int menuOption;
    double depositAmount;
    double withdrawAmount;

    do {
        showMenu();
        cout << "Please choose an option (1, 2, 3, 4): ";
        cin >> menuOption;

        switch(menuOption) {
            case 1:
                checkBalance();
                break;
            case 2:
                cout << "Deposit amount: $";
                cin >> depositAmount;
                if (depositAmount > 0) { 
                g_Balance += depositAmount;
                } else {
                    cout << "Deposit must be greater than 0" << endl;
                }
                cout << "The Balance is now: $" << g_Balance << endl;
                cout << endl;
                break;
            case 3:
                cout << "How much would you like to withdraw?: $";
                cin >> withdrawAmount;
                if (withdrawAmount <= g_Balance) {
                    g_Balance -= withdrawAmount;
                    cout << "The Balance is now: $" << g_Balance << endl;
                } else {
                    cout << "Insufficient funds." << endl;
                }
                break;
        };
    } while(menuOption != 4);

    return 0;
}