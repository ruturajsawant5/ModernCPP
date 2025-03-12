//
// Created by rutur on 11-03-2025.
//

#include "Transaction.h"
#include <iostream>


void Transaction(Account* acc)
{
    std::cout << "Transaction(Account* acc)" << std::endl;
//    std::cout << acc->GetAccountNumber() << std::endl;
//    std::cout << acc->GetBalance() << std::endl;
//    acc->Withdraw(10);
//    std::cout << acc->GetBalance() << std::endl;
//    acc->Deposit(100);
//    std::cout << acc->GetBalance() << std::endl;
//    std::cout << acc->GetInterestRate() << std::endl;
    std::cout << "--------------------" << std::endl;
    const std::type_info &ti = typeid(*acc);
    if(ti == typeid(Checking))
    {
        std::cout << "Checking" << std::endl;
        Checking *pc = static_cast<Checking*>(acc);
        std::cout << pc->GetMinimumBalance() << std::endl;
    }
    else
    {
        std::cout << "Not A Checking but " << typeid(*acc).name() << std::endl;
    }

}
