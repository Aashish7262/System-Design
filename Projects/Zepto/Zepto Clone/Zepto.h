#ifndef ZEPTO_H
#define ZEPTO_H

#include "User.h"
#include "OrderManager.h"

class Zepto {
public:
    void addToCart(User& user, int sku, int quantity);

    Order* checkout(User& user);
};

#endif
