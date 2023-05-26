#include <iostream>
#include <cassert>
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

void displayBalance(Account& account){
    cout << "Balance is: $" << account.balance << endl;
};

void deposit(Account& account, double amount) {
    if (amount > 0)
        account.balance += amount;
    else 
        cout << "Deposit must be greater than 0" << endl;
    displayBalance(account);
    
    cout << endl;
};

void testDeposit(Account& account)
{
    // Account account; //create an instance of account
    account.balance = 0; //initialize the balance 

    //Deposit $100
    double depositAmount = 100;
    deposit(account, depositAmount);

    //assert that the balance is now $100
    assert(account.balance == 100);
};

void withdraw(Account& account, double amount) {
    if (amount <= account.balance) {
        account.balance -= amount;
       displayBalance(account);
    } else
        cout << "Insufficient funds." << endl;
};

void testWithdrawl(Account& account)
{
    // Account account; //create an instance of account
    account.balance = 0; //initialize the balance 

    //withdraw $100
    double withdrawAmount = 100;
    withdraw(account, withdrawAmount);

    //assert that the balance is now $100
    assert(account.balance == 100);
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
                displayBalance(account);
                break;
            case 2:
                deposit(account, getUserInput());
                break;
            case 3:
                withdraw(account, getUserInput());
                break;
        };
    } while(menuOption != 4);

    //tests
    testDeposit(account);

    return 0;
}