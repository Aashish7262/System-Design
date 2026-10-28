#include "DarkStoreManager.h"
#include <algorithm>

DarkStoreManager& DarkStoreManager::getInstance() {
    static DarkStoreManager instance;
    return instance;
}

void DarkStoreManager::addStore(unique_ptr<DarkStore> store) {
    stores.push_back(move(store));
}

DarkStore* DarkStoreManager::findStore(
    double userX,
    double userY,
    const vector<pair<int, int>>& items
) {
    DarkStore* result = nullptr;
    double bestDistance = 1e18;

    for (const auto& store : stores) {
        double distance = store->getDistance(userX, userY);

        if (store->canFulfill(items) && distance < bestDistance) {
            bestDistance = distance;
            result = store.get();
        }
    }

    return result;
}
