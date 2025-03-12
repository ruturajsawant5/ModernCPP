#include <iostream>
#include <typeinfo>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"

int main()
{
    Checking *checking = new Checking("RURU", 1000, 50);
    Transaction(checking);
    std::cout << "----------------------------------" << std::endl;

    Savings *saving = new Savings("RURU", 1000, 0.05f);
    Transaction(saving);
    std::cout << "----------------------------------" << std::endl;

    Checking &cref = *checking;
    Transaction(cref);
    std::cout << "----------------------------------" << std::endl;

    Savings &sref = *saving;
    Transaction(sref);
    std::cout << "----------------------------------" << std::endl;


    return 0;
}