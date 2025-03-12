//
// Created by rutur on 11-03-2025.
//

#ifndef MODERNCPP_CHECKING_H
#define MODERNCPP_CHECKING_H
#include "Account.h"
#include <string>

class Checking : public Account
{
    float m_minimum_balance;
public:
    Checking(const std::string& name, float balance, float minimum_balance);
    ~Checking();

    //C++11 Inheriting Constructor
    //using Account::Account;
    void Withdraw(float amt);
    float GetMinimumBalance() const;
};


#endif // MODERNCPP_CHECKING_H
