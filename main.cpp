#include <iostream>
using namespace std;

struct Account {
    double balance;
};

void showMenu() {
    cout << " --------Menu---------" << endl;
    cout << " 1. Check balance " << endl;
    cout << " 2. Deposit " << endl;
    cout << " 3. Withdraw " << endl;
    cout << " 4. Exit " << endl;
    cout << " ---------------------" << endl;
};

void checkBalance(const Account& account){
    cout << "Balance is: $" << account.balance << endl;
};

void deposit(Account& account, double amount) {
    if (amount > 0)
        account.balance += amount;
    else 
        cout << "Deposit must be greater than 0" << endl;
    cout << "The Balance is now: $" << account.balance << endl;
    
    cout << endl;
};

void withdraw(Account& account, double amount) {
    if (amount <= account.balance) {
        account.balance -= amount;
        cout << "The Balance is now: $" << account.balance << endl;
    } else
        cout << "Insufficient funds." << endl;
};

double getUserInput() {
    double amount;
    cout << "Enter amount: $";
    cin >> amount;
    return amount;
}

int main() {

    // functionality - check balance, deposit, withdraw, show menu
    int menuOption;
    Account account;
    account.balance = 500;

    do {
        showMenu();
        cout << "Please choose an option (1, 2, 3, 4): ";
        cin >> menuOption;

        switch(menuOption) {
            case 1:
                checkBalance(account);
                break;
            case 2:
                deposit(account, getUserInput());
                break;
            case 3:
                withdraw(account, getUserInput());
                break;
        };
    } while(menuOption != 4);

    return 0;
}