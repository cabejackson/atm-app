#include <iostream>
#include "atm.h"
#include <catch2/catch_all.hpp>
using namespace std;

int main(int argc, char* argv[]) {

    BankAccount account;
    account.setBalance(500);

    ATM atm(account);
    atm.run();

    Catch::Session session; // Create a Catch2 session
    int returnCode = session.applyCommandLine(argc, argv); // Process command-line arguments
    if (returnCode != 0) // Return early if there's a command-line error
        return returnCode;
    
    return session.run(); // Run the tests
};