#ifndef DARK_STORE_MANAGER_H
#define DARK_STORE_MANAGER_H

#include "DarkStore.h"
#include <memory>
#include <vector>

using namespace std;

class DarkStoreManager {
private:
    vector<unique_ptr<DarkStore>> stores;

    DarkStoreManager() = default;

public:
    DarkStoreManager(const DarkStoreManager&) = delete;
    DarkStoreManager& operator=(const DarkStoreManager&) = delete;

    static DarkStoreManager& getInstance();

    void addStore(unique_ptr<DarkStore> store);

    DarkStore* findStore(
        double userX,
        double userY,
        const vector<pair<int, int>>& items
    );
};

#endif
