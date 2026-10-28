#include "Zepto.h"
#include <iostream>

using namespace std;

void Zepto::addToCart(
    User& user,
    int sku,
    int quantity
) {
    user.getCart().addItem(sku, quantity);

    cout << quantity
         << " item(s) added to cart"
         << endl;
}

Order* Zepto::checkout(User& user) {
    return OrderManager::getInstance().placeOrder(
        user,
        DarkStoreManager::getInstance()
    );
}
