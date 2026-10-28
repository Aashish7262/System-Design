#include <iostream>
#include <string>
using namespace std;

class Notification {
public:
    virtual void send(string message) = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class PushNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending Push Notification: " << message << endl;
    }
};

class NotificationFactory {
public:
    static Notification* createNotification(string type) {
        if (type == "EMAIL") {
            return new EmailNotification();
        }

        if (type == "SMS") {
            return new SMSNotification();
        }

        if (type == "PUSH") {
            return new PushNotification();
        }

        return nullptr;
    }
};

int main() {
    Notification* notification =
        NotificationFactory::createNotification("EMAIL");

    if (notification) {
        notification->send("Order placed successfully!");
    }

    delete notification;

    return 0;
}