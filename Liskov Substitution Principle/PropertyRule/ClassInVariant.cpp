#include <iostream>
using namespace std;
class BankAccount{
    protected:
    int balance;
    public:
    virtual void withdraw(int amount){
        if(amount <= balance){
            balance -= amount;
            cout<<"Withdrawn: "<<amount<<endl;
        } else {
            cout<<"Insufficient funds"<<endl;
        }
    }
};
class CheatClass : public BankAccount{
    public:
    CheatClass(int initialBalance){
        balance = initialBalance;
    }
    void withdraw(int amount) override{
        balance -= amount; // Cheating by allowing withdrawal without checking balance
        cout<<"Cheating! Withdrawing more than balance"<<endl;
    }
};
int main(){
    BankAccount* account = new CheatClass(100);
    account->withdraw(150); // This should not be allowed, but it is due to the override
    delete account;
    return 0;
}