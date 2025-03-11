#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"

int main()
{
//    Account acc{"RUTURAJ", 200};
//    std::cout << acc.GetBalance() << std::endl;
//    acc.Withdraw(100);
//    std::cout << acc.GetBalance() << std::endl;
//    acc.Deposit(1000);
//    std::cout << acc.GetBalance() << std::endl;
//    acc.Withdraw(100000);
//    std::cout << acc.GetBalance() << std::endl;

//    Savings sav{"Ruturaj", 100.0, 0.10};
//    std::cout << sav.GetBalance() << std::endl;
//    sav.AccumulateInterest();
//    std::cout << sav.GetBalance() << std::endl;
//    std::cout << sav.GetInterestRate() << std::endl;

    Checking check("Ruturaj", 1000);
    std::cout << check.GetBalance() << std::endl;
    check.Withdraw(999);

    return 0;
}