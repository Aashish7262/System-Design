#include "WeeklyRepStrategy.h"
#include <iostream>

using namespace std;

void WeeklyRepStrategy::replenish(
    InventoryManager& manager,
    const map<int, int>& items
) {
    for (const auto& item : items) {
        int sku = item.first;
        int quantity = item.second;

        manager.addStock(sku, quantity);

        cout << "weekly replenishment for sku "
             << sku
             << " by "
             << quantity
             << endl;
    }
}
