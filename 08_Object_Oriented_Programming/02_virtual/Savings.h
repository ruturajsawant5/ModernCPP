//
// Created by rutur on 11-03-2025.
//

#ifndef MODERNCPP_SAVINGS_H
#define MODERNCPP_SAVINGS_H
#include <string>
#include "Account.h"

class Savings : public Account {
    float m_rate;

public:
    Savings(const std::string& name, float balance, float rate);
    ~Savings();
    void AccumulateInterest();
    float GetInterestRate() const;
};


#endif // MODERNCPP_SAVINGS_H
