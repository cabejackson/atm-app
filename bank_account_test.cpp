// #include <cassert>
#include "catch.hpp"
#include "main.cpp"

void testDeposit()
{
    Account account; //create an instance of account
    account.balance = 0; //initialize the balance 

    //Deposit $100
    double depositAmount = 100;
    deposit(account, depositAmount);

    //assert that the balance is now $100
    assert(account.balance == 100);
};

int main() {
    testDeposit();

    return 0;
}