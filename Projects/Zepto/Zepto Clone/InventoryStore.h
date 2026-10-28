#ifndef INVENTORY_STORE_H
#define INVENTORY_STORE_H

#include "Product.h"
#include <vector>

using namespace std;

class InventoryStore {
public:
    virtual void addProduct(const Product& product, int quantity) = 0;
    virtual void removeProduct(int sku) = 0;
    virtual void addStock(int sku, int quantity) = 0;
    virtual bool removeStock(int sku, int quantity) = 0;
    virtual int checkStock(int sku) const = 0;
    virtual vector<Product> getAllProducts() const = 0;
    virtual const Product* getProduct(int sku) const = 0;
    virtual ~InventoryStore() = default;
};

#endif
