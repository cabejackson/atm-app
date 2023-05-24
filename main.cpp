#include <iostream>
using namespace std;

//global variables
double g_Balance = 500;
double g_DepositAmount;
double g_WithdrawAmount;

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

void deposit(double g_DepositAmount) {
    if (g_DepositAmount > 0)
        g_Balance += g_DepositAmount;
    else 
        cout << "Deposit must be greater than 0" << endl;
    cout << "The Balance is now: $" << g_Balance << endl;
    
    cout << endl;
};

void withdraw(double g_WithdrawAmount) {
    if (g_WithdrawAmount <= g_Balance) {
        g_Balance -= g_WithdrawAmount;
        cout << "The Balance is now: $" << g_Balance << endl;
    } else
        cout << "Insufficient funds." << endl;
};

int main() {

    // functionality - check balance, deposit, withdraw, show menu
    int menuOption;

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
                cin >> g_DepositAmount;
                deposit(g_DepositAmount);
                break;
            case 3:
                cout << "How much would you like to withdraw?: $";
                cin >> g_WithdrawAmount;
                withdraw(g_WithdrawAmount);
                break;
        };
    } while(menuOption != 4);

    return 0;
}