#include<iostream>
using namespace std;
class DepositOnlyAccount {
    public:
    virtual void deposit(double amount) = 0;
};
class WithdrawableAccount : public DepositOnlyAccount {
    public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawableAccount {
    private:
    double balance;
    public:
    SavingsAccount(double initialBalance) : balance(initialBalance) {}
    
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }
    
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal of: " << amount << endl;
        }
    }
    
    double getBalance() const {
        return balance;
    }
};

class FixedDepositAccount : public DepositOnlyAccount {
    private:
    double balance;
    public:
    FixedDepositAccount(double initialBalance) : balance(initialBalance) {}
    
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }
    
    double getBalance() const {
        return balance;
    }
};
class Client {
    public:
    void performTransactions(DepositOnlyAccount* account) {
        account->deposit(1000);
        
        if (WithdrawableAccount* withdrawable = dynamic_cast<WithdrawableAccount*>(account)) {
            withdrawable->withdraw(500);
        } else {
            cout << "This account does not support withdrawals." << endl;
        }
    }
};
int main() {
    
    Client client;
    SavingsAccount savings(2000);
    FixedDepositAccount fixedDeposit(1000);
    
    client.performTransactions(&savings);
    client.performTransactions(&fixedDeposit);
    return 0;
}