//
// Created by rutur on 11-03-2025.
//
#include <iostream>
#include "Savings.h"

Savings::Savings(const std::string& name, float balance, float rate) :
    Account(name, balance), m_rate(rate)
{
    std::cout << "Savings::Savings()" << std::endl;
}
Savings::~Savings()
{
    std::cout << "Savings::~Savings()" << std::endl;
}

void Savings::AccumulateInterest()
{
    m_balance += (m_balance * m_rate);
}

float Savings::GetInterestRate() const
{
    return m_rate * 100;
}