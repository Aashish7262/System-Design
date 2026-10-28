#include <iostream>
using namespace std;
class Car {
    protected:
    int speed;
    public:
    virtual void setSpeed(int s){
        speed = s;
        if(speed < 0){
            cout<<"Speed cannot be negative"<<endl;
        } else {
            cout<<"Speed set to: "<<speed<<endl;
        }
    }
};
class SportsCar : public Car {
    public:
    void setSpeed(int s) override{
        speed = s;
        if(speed < 0){
            cout<<"Sports car speed cannot be negative"<<endl;
        } else if(speed > 300){
            cout<<"Sports car speed cannot exceed 300"<<endl;
        } else {
            cout<<"Sports car speed set to: "<<speed<<endl;
        }
    }
};

int main(){
    Car* car = new SportsCar();
    car->setSpeed(350); // This should not be allowed, but it is due to the override
    delete car;
    return 0;
}