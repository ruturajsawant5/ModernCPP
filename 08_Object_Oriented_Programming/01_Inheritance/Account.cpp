//
// Created by rutur on 11-03-2025.
//
#include <iostream>
#include "Account.h"

int Account::s_ANGenerator = 1000;

Account::Account(const std::string& name, float balance): m_name(name), m_balance(balance), m_account_number(++s_ANGenerator)
{
    //how to validate here ???
}

Account::~Account()
{
}

const std::string& Account::GetName() const
{
    return m_name;
}

float Account::GetBalance() const
{
    return m_balance;
}

int Account::GetAccountNumber() const
{
    return m_account_number;
}

void Account::Withdraw(float amt)
{
    if(amt < m_balance)
        m_balance -= amt;
    else
        std::cout << "Insufficient Balance" << std::endl;
}

void Account::Deposit(float amt)
{
    if(amt <= 0)
    {
        std::cout << "Invalid Deposit" << std::endl;
        return;
    }
    m_balance += amt;
}

void Account::AccumulateInterest()
{

}

float Account::GetInterestRate() const
{
    return 0.0f;
}
