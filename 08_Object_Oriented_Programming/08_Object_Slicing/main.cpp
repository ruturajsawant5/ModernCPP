#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
int main()
{
    Checking ch("BOB", 100);
    Account *account = &ch; //Upcast works
    std::cout << account->GetName() << std::endl;
    account->Withdraw(100);

    Account account2 = ch; //does object slicing
    //checking part is sliced out

    //CTE 'initializing': cannot convert from 'Account *' to 'Checking *'
    //Checking *checking = &account2;

    Checking *checking = static_cast<Checking*>(account); //WORKS have to do manually
    std::cout << account->GetName() << std::endl;
    account->Withdraw(100);


    return 0;
}