#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class TV {
public:
    void turnOn() {
        cout << "TV is ON" << endl;
    }

    void turnOff() {
        cout << "TV is OFF" << endl;
    }
};

class TurnOnCommand : public Command {
private:
    TV* tv;

public:
    TurnOnCommand(TV* tv) {
        this->tv = tv;
    }

    void execute() override {
        tv->turnOn();
    }
};

class TurnOffCommand : public Command {
private:
    TV* tv;

public:
    TurnOffCommand(TV* tv) {
        this->tv = tv;
    }

    void execute() override {
        tv->turnOff();
    }
};

class Remote {
private:
    Command* command;

public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void pressButton() {
        command->execute();
    }
};

int main() {

    TV tv;

    TurnOnCommand turnOn(&tv);
    TurnOffCommand turnOff(&tv);

    Remote remote;

    remote.setCommand(&turnOn);
    remote.pressButton();

    remote.setCommand(&turnOff);
    remote.pressButton();

    return 0;
}