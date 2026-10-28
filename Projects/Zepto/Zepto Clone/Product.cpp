#include "Product.h"

Product::Product(int sku, string name, double price) {
    this->sku = sku;
    this->name = name;
    this->price = price;
}

int Product::getSku() const {
    return sku;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}
