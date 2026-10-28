#include "Order.h"
#include <iostream>

using namespace std;

Order::Order(
    int orderId,
    User* user,
    vector<pair<int, int>> items,
    double total,
    DeliveryPartner* deliveryPartner
) {
    this->orderId = orderId;
    this->user = user;
    this->items = move(items);
    this->total = total;
    this->deliveryPartner = deliveryPartner;
}

int Order::getOrderId() const {
    return orderId;
}

double Order::getTotal() const {
    return total;
}

void Order::printOrder() const {
    cout << endl;
    cout << "order id: " << orderId << endl;
    cout << "user: " << user->getName() << endl;
    cout << "total: " << total << endl;

    if (deliveryPartner) {
        cout << "delivery partner: "
             << deliveryPartner->getName()
             << endl;
    }
}
