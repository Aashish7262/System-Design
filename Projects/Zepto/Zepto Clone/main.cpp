#include <iostream>
#include <memory>
#include <map>

#include "ProductFactory.h"
#include "DBInventoryStore.h"
#include "InventoryManager.h"
#include "ThresholdRepStrategy.h"
#include "WeeklyRepStrategy.h"
#include "DarkStore.h"
#include "DarkStoreManager.h"
#include "User.h"
#include "Zepto.h"

using namespace std;

int main() {

    Product milk =
        ProductFactory::createProduct(101, "milk", 40);

    Product bread =
        ProductFactory::createProduct(102, "bread", 50);

    Product eggs =
        ProductFactory::createProduct(103, "eggs", 70);

    auto store1Data =
        make_unique<DBInventoryStore>();

    auto store1Inventory =
        make_unique<InventoryManager>(
            store1Data.get()
        );

    store1Inventory->addProduct(milk, 10);
    store1Inventory->addProduct(bread, 5);
    store1Inventory->addProduct(eggs, 2);

    auto store1 =
        make_unique<DarkStore>(
            "dark store 1",
            2,
            3,
            move(store1Inventory),
            make_unique<ThresholdRepStrategy>(5)
        );

    auto store2Data =
        make_unique<DBInventoryStore>();

    auto store2Inventory =
        make_unique<InventoryManager>(
            store2Data.get()
        );

    store2Inventory->addProduct(milk, 20);
    store2Inventory->addProduct(bread, 20);
    store2Inventory->addProduct(eggs, 10);

    auto store2 =
        make_unique<DarkStore>(
            "dark store 2",
            8,
            8,
            move(store2Inventory),
            make_unique<WeeklyRepStrategy>()
        );

    DarkStoreManager& storeManager =
        DarkStoreManager::getInstance();

    storeManager.addStore(move(store1));
    storeManager.addStore(move(store2));

    User user(1, "aashish", 2.5, 3.5);

    Zepto zepto;

    zepto.addToCart(user, 101, 2);
    zepto.addToCart(user, 102, 1);

    Order* order = zepto.checkout(user);

    if (order) {
        order->printOrder();
    }

    return 0;
}
