#include "DBInventoryStore.h"

void DBInventoryStore::addProduct(const Product& product, int quantity) {
    products[product.getSku()] = product;
    stock[product.getSku()] += quantity;
}

void DBInventoryStore::removeProduct(int sku) {
    products.erase(sku);
    stock.erase(sku);
}

void DBInventoryStore::addStock(int sku, int quantity) {
    if (products.count(sku)) {
        stock[sku] += quantity;
    }
}

bool DBInventoryStore::removeStock(int sku, int quantity) {
    if (!products.count(sku) || stock[sku] < quantity) {
        return false;
    }

    stock[sku] -= quantity;
    return true;
}

int DBInventoryStore::checkStock(int sku) const {
    auto it = stock.find(sku);

    if (it == stock.end()) {
        return 0;
    }

    return it->second;
}

vector<Product> DBInventoryStore::getAllProducts() const {
    vector<Product> result;

    for (const auto& item : products) {
        result.push_back(item.second);
    }

    return result;
}

const Product* DBInventoryStore::getProduct(int sku) const {
    auto it = products.find(sku);

    if (it == products.end()) {
        return nullptr;
    }

    return &it->second;
}
