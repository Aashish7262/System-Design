#include "Cart.h"

void Cart::addItem(int sku, int quantity) {
    for (auto& item : items) {
        if (item.first == sku) {
            item.second += quantity;
            return;
        }
    }

    items.push_back({sku, quantity});
}

void Cart::removeItem(int sku, int quantity) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->first == sku) {
            it->second -= quantity;

            if (it->second <= 0) {
                items.erase(it);
            }

            return;
        }
    }
}

double Cart::getTotal(const InventoryManager& manager) const {
    double total = 0;

    for (const auto& item : items) {
        const Product* product = manager.getProduct(item.first);

        if (product) {
            total += product->getPrice() * item.second;
        }
    }

    return total;
}

const vector<pair<int, int>>& Cart::getItems() const {
    return items;
}

bool Cart::empty() const {
    return items.empty();
}

void Cart::clear() {
    items.clear();
}
