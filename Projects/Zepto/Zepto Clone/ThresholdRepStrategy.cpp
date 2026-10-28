#include "ThresholdRepStrategy.h"
#include <iostream>

using namespace std;

ThresholdRepStrategy::ThresholdRepStrategy(int threshold) {
    this->threshold = threshold;
}

void ThresholdRepStrategy::replenish(
    InventoryManager& manager,
    const map<int, int>& items
) {
    for (const auto& item : items) {
        int sku = item.first;
        int currentStock = manager.checkStock(sku);

        if (currentStock < threshold) {
            int quantityToAdd = threshold - currentStock;
            manager.addStock(sku, quantityToAdd);

            cout << "replenished sku "
                 << sku
                 << " by "
                 << quantityToAdd
                 << endl;
        }
    }
}
