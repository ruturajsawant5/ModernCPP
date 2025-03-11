//
// Created by rutur on 11-03-2025.
//

#include "Checking.h"
#include <iostream>

void Checking::Withdraw(float amt)
{
    if((m_balance - amt) > 50)
        Account::Withdraw(amt);
    else
         std::cout << "Invalid Amount" << std::endl;
}

//Checking::Checking(const std::string& name, float balance) : Account(name, balance)
//{
//
//}