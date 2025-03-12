//
// Created by rutur on 11-03-2025.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Account.h"
#include "Checking.h"
#include "Savings.h"

//void Transaction(Checking* acc);
//void Transaction(Savings* acc);
void Transaction(Account* acc);
void Transaction(Account& acc);

#endif //TRANSACTION_H
