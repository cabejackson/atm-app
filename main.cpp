#include <iostream>
#include "atm.h"
#include <catch2/catch_all.hpp>
using namespace std;


// double getUserInput() {
//     double amount;
//     cout << "Enter amount: $";
//     cin >> amount;
//     return amount;
// }
// int argc, char* argv[]
int main(int argc, char* argv[]) {

    // functionality - check balance, deposit, withdraw, show menu
    // int menuOption;
    // Account account;
    // account.balance = 500;

    // do {
    //     showMenu();
    //     cout << "Please choose an option (1, 2, 3, 4): ";
    //     cin >> menuOption;

    //     switch(menuOption) {
    //         case 1:
    //             displayBalance(account);
    //             break;
    //         case 2:
    //             deposit(account, getUserInput());
    //             break;
    //         case 3:
    //             withdraw(account, getUserInput());
    //             break;
    //     };
    // } while(menuOption != 4);

    BankAccount account;
    account.setBalance(500);

    ATM atm(account);
    atm.run();

    Catch::Session session; // Create a Catch2 session
    int returnCode = session.applyCommandLine(argc, argv); // Process command-line arguments
    if (returnCode != 0) // Return early if there's a command-line error
        return returnCode;
    
    return session.run(); // Run the tests

    return 0;
};