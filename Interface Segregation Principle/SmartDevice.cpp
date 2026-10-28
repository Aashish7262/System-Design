#include <iostream>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class SmartDeviceWithRecord : public SmartDevice {
public:
    virtual void record() = 0;
};
class SmartDeviceWithPlayMusic : public SmartDevice {
public:
    virtual void playMusic() = 0;
};  

class SmartDeviceWithRecordAndPlayMusic : public SmartDeviceWithRecord, public SmartDeviceWithPlayMusic {
public:
    void turnOn() override {
        cout << "Smart device is turned on" << endl;
    }

    void turnOff() override {
        cout << "Smart device is turned off" << endl;
    }

    void record() override {
        cout << "Smart device is recording" << endl;
    }

    void playMusic() override {
        cout << "Smart device is playing music" << endl;
    }
};

int main() {
    SmartDeviceWithRecordAndPlayMusic smartDevice;
    smartDevice.turnOn();
    smartDevice.record();
    smartDevice.playMusic();
    smartDevice.turnOff();

    return 0;
}