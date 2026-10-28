#ifndef PRODUCT_FACTORY_H
#define PRODUCT_FACTORY_H

#include "Product.h"

class ProductFactory {
public:
    static Product createProduct(int sku, string name, double price);
};

#endif
