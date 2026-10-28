#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    int sku;
    string name;
    double price;

public:
    Product(int sku, string name, double price);

    int getSku() const;
    string getName() const;
    double getPrice() const;
};

#endif
