#include <tests/catch_all.hpp>
#include "main.cpp"

TEST_CASE("Deposit increases total balance") {
    Account account;
    account.balance = 0;

    double depositAmount = 100;
    deposit(account, depositAmount);

    REQUIRE(account.balance == 100);
}
