#include <iostream>
using namespace std;

class Coffee {
public:
    virtual int getCost() = 0;
    virtual void getDescription() = 0;
    virtual ~Coffee() = default;
};

class SimpleCoffee : public Coffee {
public:
    int getCost() override {
        return 50;
    }

    void getDescription() override {
        cout << "Simple Coffee";
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* coffee) {
        this->coffee = coffee;
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    int getCost() override {
        return coffee->getCost() + 10;
    }

    void getDescription() override {
        coffee->getDescription();
        cout << " + Milk";
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    int getCost() override {
        return coffee->getCost() + 5;
    }

    void getDescription() override {
        coffee->getDescription();
        cout << " + Sugar";
    }
};

int main() {

    Coffee* coffee = new SimpleCoffee();

    coffee = new MilkDecorator(coffee);

    coffee = new SugarDecorator(coffee);

    coffee->getDescription();

    cout << endl;
    cout << "Total Cost: " << coffee->getCost() << endl;

    return 0;
}