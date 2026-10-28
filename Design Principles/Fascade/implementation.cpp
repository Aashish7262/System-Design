#include <iostream>
using namespace std;

class Restaurant {
public:
    bool checkAvailability() {
        cout << "Checking restaurant availability..." << endl;
        return true;
    }
};

class Payment {
public:
    void processPayment() {
        cout << "Processing payment..." << endl;
    }
};

class Kitchen {
public:
    void prepareFood() {
        cout << "Preparing food..." << endl;
    }
};

class Delivery {
public:
    void assignDelivery() {
        cout << "Assigning delivery partner..." << endl;
    }
};

class Notification {
public:
    void sendNotification() {
        cout << "Sending order confirmation..." << endl;
    }
};

class OrderFacade {
private:
    Restaurant restaurant;
    Payment payment;
    Kitchen kitchen;
    Delivery delivery;
    Notification notification;

public:
    void placeOrder() {

        if (!restaurant.checkAvailability()) {
            cout << "Restaurant is unavailable." << endl;
            return;
        }

        payment.processPayment();
        kitchen.prepareFood();
        delivery.assignDelivery();
        notification.sendNotification();

        cout << "Order placed successfully!" << endl;
    }
};

int main() {

    OrderFacade orderFacade;

    orderFacade.placeOrder();

    return 0;
}