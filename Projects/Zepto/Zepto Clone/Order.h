#ifndef ORDER_H
#define ORDER_H

#include "User.h"
#include "DeliveryPartner.h"
#include <vector>
#include <utility>

using namespace std;

class Order {
private:
    int orderId;
    User* user;
    vector<pair<int, int>> items;
    double total;
    DeliveryPartner* deliveryPartner;

public:
    Order(
        int orderId,
        User* user,
        vector<pair<int, int>> items,
        double total,
        DeliveryPartner* deliveryPartner
    );

    int getOrderId() const;
    double getTotal() const;

    void printOrder() const;
};

#endif
