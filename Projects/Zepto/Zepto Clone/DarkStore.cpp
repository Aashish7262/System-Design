#include "DarkStore.h"
#include <cmath>

DarkStore::DarkStore(
    string name,
    double x,
    double y,
    unique_ptr<InventoryManager> inventoryManager,
    unique_ptr<ReplenishStrategy> replenishStrategy
) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->inventoryManager = move(inventoryManager);
    this->replenishStrategy = move(replenishStrategy);
}

string DarkStore::getName() const {
    return name;
}

double DarkStore::getX() const {
    return x;
}

double DarkStore::getY() const {
    return y;
}

double DarkStore::getDistance(double userX, double userY) const {
    double dx = x - userX;
    double dy = y - userY;

    return sqrt(dx * dx + dy * dy);
}

bool DarkStore::canFulfill(const vector<pair<int, int>>& items) const {
    for (const auto& item : items) {
        if (inventoryManager->checkStock(item.first) < item.second) {
            return false;
        }
    }

    return true;
}

bool DarkStore::reserveItems(const vector<pair<int, int>>& items) {
    if (!canFulfill(items)) {
        return false;
    }

    for (const auto& item : items) {
        if (!inventoryManager->removeStock(item.first, item.second)) {
            return false;
        }
    }

    return true;
}

void DarkStore::replenish(const map<int, int>& items) {
    replenishStrategy->replenish(*inventoryManager, items);
}

InventoryManager& DarkStore::getInventoryManager() {
    return *inventoryManager;
}
