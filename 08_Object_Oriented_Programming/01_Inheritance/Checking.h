//
// Created by rutur on 11-03-2025.
//

#ifndef MODERNCPP_CHECKING_H
#define MODERNCPP_CHECKING_H
#include "Account.h"
#include <string>

class Checking : public Account
{
public:
    //Checking(const std::string& name, float balance);
    //C++11 Inheriting Constructor
    using Account::Account;
    void Withdraw(float amt);
};


#endif // MODERNCPP_CHECKING_H
