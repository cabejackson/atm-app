#include <iostream>
#include "bankaccount.h"
#include "atm.h"
#include <catch2/catch_all.hpp>

TEST_CASE("Deposit increases total balance"){
    //arrange
    BankAccount account; //create an instance of account
    account.setBalance(0); //initialize the balance 
    
    //act - Deposit $100
    double depositAmount = 100;
    account.deposit(depositAmount);

    //assert that the balance is now $100
    double expectedBalance = 100;
    REQUIRE(account.getBalance() == expectedBalance);
};

TEST_CASE("Negative deposit does not change total balance"){
    //arrange
    BankAccount account; //create an instance of account
    account.setBalance(0); //initialize the balance 
    
    //act -Deposit -$100
    double depositAmount = -100;
    account.deposit(depositAmount);

    //assert that the balance is now $100
    double expectedBalance = 0;
    REQUIRE(account.getBalance() == expectedBalance);
};

TEST_CASE("Withdraw decreases total balance"){
    //arrange
    BankAccount account; //create an instance of account
    account.setBalance(100); //initialize the balance

    //act -withdraw $50
    double withdrawAmount = 50;
    account.withdraw(withdrawAmount);

    //assert that the balance is now $50
    double expectedBalance = 50;
    REQUIRE(account.getBalance() == expectedBalance);
};

// TEST_CASE("Withdraw does not allow overdraw"){
//     BankAccount account; //create an instance of account
//     account.balance = 100; //initialize the balance

//     //withdraw $101 (more than current balance)
//     double withdrawAmount = 101;
//     withdraw(account, withdrawAmount);

//     //assert that the balance is still 100
//     REQUIRE(account.balance == 100);
// };

// TEST_CASE("Negative withdraw does not change total balance"){
//     BankAccount account; //create an instance of account
//     account.balance = 100; //initialize the balance

//     //withdraw -$10
//     double withdrawAmount = -10;
//     withdraw(account, withdrawAmount);

//     //assert that the balance is still 100
//     REQUIRE(account.balance == 100);
// };

// TEST_CASE("Multiple deposits and withdrawals") {
//     BankAccount account; //create an instance of account
//     account.balance = 0; //initialize the balance

//     deposit(account, 100);
//     REQUIRE(account.balance == 100);

//     withdraw(account, 25);
//     REQUIRE(account.balance == 75);

//     deposit(account, 100);
//     REQUIRE(account.balance == 175);

//     withdraw(account, 25);
//     REQUIRE(account.balance == 150);

//     deposit(account, 100);
//     REQUIRE(account.balance == 250);

//     withdraw(account, 50);
//     REQUIRE(account.balance == 200);
// };