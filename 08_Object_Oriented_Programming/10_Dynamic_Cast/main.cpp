#include <iostream>
#include <typeinfo>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"

int main()
{
    int x{};
    float y{};

    const std::type_info &t1 = typeid(x);
    std::cout << t1.name() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    const std::type_info &t2 = typeid(x);
    std::cout << t2.name() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    Checking *checking = new Checking("RURU", 1000, 50);
    Transaction(checking);
    std::cout << "----------------------------------" << std::endl;

    Savings *saving = new Savings("RURU", 1000, 0.05f);
    Transaction(saving);
    std::cout << "----------------------------------" << std::endl;

    //only works if virtual
    Account &refAcc = *new Savings("RURU", 1000, 0.05f);
    const std::type_info &t3 = typeid(refAcc);
    std::cout << t3.name() << std::endl;
    std::cout << "----------------------------------" << std::endl;

    return 0;
}