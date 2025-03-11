#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
int main()
{
    Account ac1("Ruturaj", 30);
    std::cout << "--------------------------------------" << std::endl;
    Savings sc1("Ruturaj", 50, 0.05);
    std::cout << "--------------------------------------" << std::endl;
    Checking cc1("Ruturaj", 50);
    std::cout << "--------------------------------------" << std::endl;
//    Transaction(&ac1);
//    std::cout << "--------------------------------------" << std::endl;
//    Transaction(&sc1);
//    std::cout << "--------------------------------------" << std::endl;
//    Transaction(&cc1);
//    std::cout << "--------------------------------------" << std::endl;

    std::cout << "No Virtual all call Account Function" << std::endl;
    Account* ptr = &ac1;
    Transaction(ptr);
    std::cout << "--------------------------------------" << std::endl;
    ptr = &sc1;
    Transaction(ptr);
    std::cout << "--------------------------------------" << std::endl;
    ptr = &cc1;
    Transaction(ptr);
    std::cout << "--------------------------------------" << std::endl;


    return 0;
}