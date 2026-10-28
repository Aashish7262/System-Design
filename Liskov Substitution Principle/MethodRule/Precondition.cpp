
#include <iostream>
using namespace std;
class UserPassword{
    protected:
    string password;
    public:
    virtual void setPassword(string pwd){
        password = pwd;
        if(password.length() < 8){
            cout<<"Password must be at least 8 characters long"<<endl;
        } else {
            cout<<"Password set to: "<<password<<endl;
        }
    }
};
class AdminUser : public UserPassword{
    public:
    void setPassword(string pwd) override{
        password = pwd;
        if(password.length() < 12){
            cout<<"Admin password must be at least 12 characters long"<<endl;
        } else {
            cout<<"Admin password set to: "<<password<<endl;
        }
    }
};
int main(){
    UserPassword* user = new AdminUser();
    user->setPassword("short"); // This should not be allowed, but it is due to the override
    delete user;
    return 0;
}