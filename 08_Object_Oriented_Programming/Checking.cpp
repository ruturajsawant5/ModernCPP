//
// Created by rutur on 11-03-2025.
//

#include "Checking.h"
#include <iostream>

void Checking::Withdraw(float amt)
{
    if(m_balance - amt < 50)
    {
        std::cout << "Minimum Balance of 50 is required" << std::endl;
        return;
    }
    m_balance -= amt;
}

Checking::Checking(const std::string& name, float balance) : Account(name, balance)
{

}