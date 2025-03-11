//
// Created by rutur on 11-03-2025.
//

#include "Transaction.h"
#include <iostream>

//void Transaction(Checking* acc)
//{
//    std::cout << "Transaction(Checking* acc)" << std::endl;
//}
//
//void Transaction(Savings* acc)
//{
//    std::cout << "Transaction(Savings* acc)" << std::endl;
//}

void Transaction(Account* acc)
{
    std::cout << "Transaction(Account* acc)" << std::endl;
    std::cout << acc->GetAccountNumber() << std::endl;
    std::cout << acc->GetBalance() << std::endl;
    acc->Withdraw(10);
    std::cout << acc->GetBalance() << std::endl;
    acc->Deposit(100);
    std::cout << acc->GetBalance() << std::endl;
    std::cout << acc->GetInterestRate() << std::endl;
}
