#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "InventoryStore.h"
#include <vector>

using namespace std;

class InventoryManager {
private:
    InventoryStore* store;

public:
    InventoryManager(InventoryStore* store);

    void addProduct(const Product& product, int quantity);
    void removeProduct(int sku);
    void addStock(int sku, int quantity);
    bool removeStock(int sku, int quantity);
    int checkStock(int sku) const;
    vector<Product> getAvailableProducts() const;
    vector<Product> getAllProducts() const;
    const Product* getProduct(int sku) const;
};

#endif
