#ifndef DARK_STORE_H
#define DARK_STORE_H

#include "InventoryManager.h"
#include "ReplenishStrategy.h"
#include <memory>
#include <vector>
#include <map>
#include <string>

using namespace std;

class DarkStore {
private:
    string name;
    double x;
    double y;
    unique_ptr<InventoryManager> inventoryManager;
    unique_ptr<ReplenishStrategy> replenishStrategy;

public:
    DarkStore(
        string name,
        double x,
        double y,
        unique_ptr<InventoryManager> inventoryManager,
        unique_ptr<ReplenishStrategy> replenishStrategy
    );

    string getName() const;
    double getX() const;
    double getY() const;

    double getDistance(double userX, double userY) const;
    bool canFulfill(const vector<pair<int, int>>& items) const;
    bool reserveItems(const vector<pair<int, int>>& items);
    void replenish(const map<int, int>& items);

    InventoryManager& getInventoryManager();
};

#endif
