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

Checking::Checking(const std::string& name, float balance, float minimum_balance) : Account(name, balance), m_minimum_balance(minimum_balance)
{
    std::cout << "Checking::Checking()" << std::endl;
}

Checking::~Checking()
{
    std::cout << "Checking::~Checking()" << std::endl;
}

float Checking::GetMinimumBalance() const
{
    return m_minimum_balance;
}