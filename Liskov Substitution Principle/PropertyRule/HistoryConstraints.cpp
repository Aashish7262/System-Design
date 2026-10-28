#include <iostream>
using namespace std;
class Account {
    int balance;
public:
void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }
};

class FixedDepositAccount : public Account {
public:
    void withdraw(int amount) {
        cout << "Withdrawals are not allowed from Fixed Deposit Account" << endl;
    }
};

int main() {
    Account* account = new FixedDepositAccount();
    account->withdraw(100); // This should not be allowed, but it is due to the override
    delete account;
    return 0;
}