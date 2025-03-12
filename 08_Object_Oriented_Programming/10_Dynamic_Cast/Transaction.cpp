//
// Created by rutur on 11-03-2025.
//

#include "Transaction.h"
#include <iostream>


void Transaction(Account* acc)
{
    std::cout << "Transaction(Account* acc)" << std::endl;
    Checking* pc = dynamic_cast<Checking*>(acc);
    if(pc != nullptr)
    {
        std::cout << "Checking" << std::endl;
        std::cout << pc->GetMinimumBalance() << std::endl;
    }
    else
    {
        std::cout << "Not A Checking but " << std::endl;
    }
}

void Transaction(Account& acc)
{
    std::cout << "Transaction(Account& acc)" << std::endl;
    try
    {
        Checking& pc = dynamic_cast<Checking&>(acc);
        std::cout << "Checking" << std::endl;
        std::cout << pc.GetMinimumBalance() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
