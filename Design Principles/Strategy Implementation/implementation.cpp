#include <iostream>
using namespace std;

class RouteStrategy {
public:
    virtual void buildRoute() = 0;
    virtual ~RouteStrategy() = default;
};

class CarStrategy : public RouteStrategy {
public:
    void buildRoute() override {
        cout << "Calculating route for car" << endl;
    }
};

class BikeStrategy : public RouteStrategy {
public:
    void buildRoute() override {
        cout << "Calculating route for bike" << endl;
    }
};

class WalkingStrategy : public RouteStrategy {
public:
    void buildRoute() override {
        cout << "Calculating route for walking" << endl;
    }
};

class Navigation {
private:
    RouteStrategy* strategy;

public:
    Navigation(RouteStrategy* strategy) {
        this->strategy = strategy;
    }

    void navigate() {
        strategy->buildRoute();
    }
};

int main() {
    CarStrategy car;
    Navigation navigation(&car);

    navigation.navigate();

    return 0;
}