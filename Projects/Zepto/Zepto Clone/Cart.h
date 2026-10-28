#ifndef CART_H
#define CART_H

#include "InventoryManager.h"
#include <vector>
#include <utility>

using namespace std;

class Cart {
private:
    vector<pair<int, int>> items;

public:
    void addItem(int sku, int quantity);
    void removeItem(int sku, int quantity);
    double getTotal(const InventoryManager& manager) const;
    const vector<pair<int, int>>& getItems() const;
    bool empty() const;
    void clear();
};

#endif
