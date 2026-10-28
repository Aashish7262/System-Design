#include <iostream>
using namespace std;

class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Human : public Workable, public Eatable {
public:
    void work() override {
        cout << "Human is working" << endl;
    }

    void eat() override {
        cout << "Human is eating" << endl;
    }
};

class Robot : public Workable {
public:
    void work() override {
        cout << "Robot is working" << endl;
    }
};

int main() {
    Human human;
    human.work();
    human.eat();

    Robot robot;
    robot.work();

    return 0;
}