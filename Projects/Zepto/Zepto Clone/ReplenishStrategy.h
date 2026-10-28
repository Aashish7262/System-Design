#ifndef REPLENISH_STRATEGY_H
#define REPLENISH_STRATEGY_H

#include "InventoryManager.h"
#include <map>

using namespace std;

class ReplenishStrategy {
public:
    virtual void replenish(
        InventoryManager& manager,
        const map<int, int>& items
    ) = 0;

    virtual ~ReplenishStrategy() = default;
};

#endif
