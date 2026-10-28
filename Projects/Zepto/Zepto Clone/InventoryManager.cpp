#include "InventoryManager.h"

InventoryManager::InventoryManager(InventoryStore* store) {
    this->store = store;
}

void InventoryManager::addProduct(const Product& product, int quantity) {
    store->addProduct(product, quantity);
}

void InventoryManager::removeProduct(int sku) {
    store->removeProduct(sku);
}

void InventoryManager::addStock(int sku, int quantity) {
    store->addStock(sku, quantity);
}

bool InventoryManager::removeStock(int sku, int quantity) {
    return store->removeStock(sku, quantity);
}

int InventoryManager::checkStock(int sku) const {
    return store->checkStock(sku);
}

vector<Product> InventoryManager::getAvailableProducts() const {
    vector<Product> available;

    for (const Product& product : store->getAllProducts()) {
        if (store->checkStock(product.getSku()) > 0) {
            available.push_back(product);
        }
    }

    return available;
}

vector<Product> InventoryManager::getAllProducts() const {
    return store->getAllProducts();
}

const Product* InventoryManager::getProduct(int sku) const {
    return store->getProduct(sku);
}
