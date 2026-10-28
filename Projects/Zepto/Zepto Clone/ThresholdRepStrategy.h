#ifndef THRESHOLD_REP_STRATEGY_H
#define THRESHOLD_REP_STRATEGY_H

#include "ReplenishStrategy.h"

class ThresholdRepStrategy : public ReplenishStrategy {
private:
    int threshold;

public:
    ThresholdRepStrategy(int threshold);

    void replenish(
        InventoryManager& manager,
        const map<int, int>& items
    ) override;
};

#endif
