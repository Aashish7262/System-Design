#ifndef WEEKLY_REP_STRATEGY_H
#define WEEKLY_REP_STRATEGY_H

#include "ReplenishStrategy.h"

class WeeklyRepStrategy : public ReplenishStrategy {
public:
    void replenish(
        InventoryManager& manager,
        const map<int, int>& items
    ) override;
};

#endif
