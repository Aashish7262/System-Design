#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include "Order.h"
#include "DarkStoreManager.h"
#include <memory>
#include <vector>

using namespace std;

class OrderManager {
private:
    vector<unique_ptr<Order>> orders;
    vector<unique_ptr<DeliveryPartner>> deliveryPartners;
    int nextOrderId;

    OrderManager();

public:
    OrderManager(const OrderManager&) = delete;
    OrderManager& operator=(const OrderManager&) = delete;

    static OrderManager& getInstance();

    Order* placeOrder(
        User& user,
        DarkStoreManager& storeManager
    );
};

#endif
