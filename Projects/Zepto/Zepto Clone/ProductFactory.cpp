#include "ProductFactory.h"

Product ProductFactory::createProduct(int sku, string name, double price) {
    return Product(sku, name, price);
}
