#ifndef DB_INVENTORY_STORE_H
#define DB_INVENTORY_STORE_H

#include "InventoryStore.h"
#include <map>
#include <vector>

using namespace std;

class DBInventoryStore : public InventoryStore {
private:
    map<int, Product> products;
    map<int, int> stock;

public:
    void addProduct(const Product& product, int quantity) override;
    void removeProduct(int sku) override;
    void addStock(int sku, int quantity) override;
    bool removeStock(int sku, int quantity) override;
    int checkStock(int sku) const override;
    vector<Product> getAllProducts() const override;
    const Product* getProduct(int sku) const override;
};

#endif
