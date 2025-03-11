//
// Created by rutur on 11-03-2025.
//

#ifndef MODERNCPP_ACCOUNT_H
#define MODERNCPP_ACCOUNT_H

#include <string>

class Account
{
private:
    std::string m_name;
    int m_account_number;
    static int s_ANGenerator;

protected:
    float m_balance;

public:
    Account(const std::string& name, float balance);
    ~Account();
    const std::string& GetName() const;
    float GetBalance() const;
    int GetAccountNumber() const;

    void Withdraw(float amt);
    void Deposit(float amt);
    void AccumulateInterest();
    float GetInterestRate() const;
};


#endif // MODERNCPP_ACCOUNT_H
