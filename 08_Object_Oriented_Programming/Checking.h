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
    Checking(const std::string& name, float balance);
    void Withdraw(float amt);
};


#endif // MODERNCPP_CHECKING_H
