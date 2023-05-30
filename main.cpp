#include <iostream>
#include <catch2/catch_all.hpp>
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
};

TEST_CASE("Deposit increases total balance"){
    Account account; //create an instance of account
    account.balance = 0; //initialize the balance 
    
    //Deposit $100
    double depositAmount = 100;
    deposit(account, depositAmount);

    //assert that the balance is now $100
    REQUIRE(account.balance == 100);
};

TEST_CASE("Negative deposit does not change total balance"){
    Account account; //create an instance of account
    account.balance = 0; //initialize the balance 
    
    //Deposit -$100
    double depositAmount = -100;
    deposit(account, depositAmount);

    //assert that the balance is now $100
    REQUIRE(account.balance == 0);
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

TEST_CASE("Withdraw decreases total balance"){
    Account account; //create an instance of account
    account.balance = 100; //initialize the balance

    //withdraw $50
    double withdrawAmount = 50;
    withdraw(account, withdrawAmount);

    //assert that the balance is now $50
    REQUIRE(account.balance == 50);
};

TEST_CASE("Withdraw does not allow overdraw"){
    Account account; //create an instance of account
    account.balance = 100; //initialize the balance

    //withdraw $101 (more than current balance)
    double withdrawAmount = 101;
    withdraw(account, withdrawAmount);

    //assert that the balance is still 100
    REQUIRE(account.balance == 100);
};

TEST_CASE("Negative withdraw does not change total balance"){
    Account account; //create an instance of account
    account.balance = 100; //initialize the balance

    //withdraw -$10
    double withdrawAmount = -10;
    withdraw(account, withdrawAmount);

    //assert that the balance is still 100
    REQUIRE(account.balance == 100);
};

double getUserInput() {
    double amount;
    cout << "Enter amount: $";
    cin >> amount;
    return amount;
}

int main(int argc, char* argv[]) {

    Catch::Session session; // Create a Catch2 session
    int returnCode = session.applyCommandLine(argc, argv); // Process command-line arguments
    if (returnCode != 0) // Return early if there's a command-line error
        return returnCode;
    
    return session.run(); // Run the tests

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

    return 0;
}