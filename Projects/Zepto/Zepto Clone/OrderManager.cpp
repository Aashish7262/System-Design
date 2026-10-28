#include "OrderManager.h"
#include <iostream>

using namespace std;

OrderManager::OrderManager() {
    nextOrderId = 1;
}

OrderManager& OrderManager::getInstance() {
    static OrderManager instance;
    return instance;
}

Order* OrderManager::placeOrder(
    User& user,
    DarkStoreManager& storeManager
) {
    Cart& cart = user.getCart();

    if (cart.empty()) {
        cout << "cart is empty" << endl;
        return nullptr;
    }

    DarkStore* store = storeManager.findStore(
        user.getX(),
        user.getY(),
        cart.getItems()
    );

    if (!store) {
        cout << "no store can fulfill the order" << endl;
        return nullptr;
    }

    double total = cart.getTotal(
        store->getInventoryManager()
    );

    if (!store->reserveItems(cart.getItems())) {
        cout << "unable to reserve items" << endl;
        return nullptr;
    }

    auto partner = make_unique<DeliveryPartner>(
        deliveryPartners.size() + 1,
        "delivery partner"
    );

    DeliveryPartner* partnerPtr = partner.get();
    deliveryPartners.push_back(move(partner));

    auto order = make_unique<Order>(
        nextOrderId++,
        &user,
        cart.getItems(),
        total,
        partnerPtr
    );

    Order* result = order.get();

    orders.push_back(move(order));
    cart.clear();

    cout << "order placed from "
         << store->getName()
         << endl;

    return result;
}
