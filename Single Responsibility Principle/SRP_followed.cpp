#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
private:
    vector<Product> products;
public:
    void addProduct(Product product) {
        products.push_back(product);
    }

    const vector<Product>& getProducts() const {
        return products;
    }

    double calculateTotalPrice() const {
        double total = 0;
        for (const auto& product : products) {
            total += product.price;
        }
        return total;
    }
};

class InvoicePrinter {
private:
    const ShoppingCart& cart;
public:
    InvoicePrinter(const ShoppingCart& cart) : cart(cart) {}

    void printInvoice() {
        cout << "Invoice:" << endl;
        for (const auto& product : cart.getProducts()) {
            cout << "Product: " << product.name << ", Price: " << product.price << endl;
        }
        cout << "Total Price: " << cart.calculateTotalPrice() << endl;
    }
};

class DatabaseSaver {
    private:
    const ShoppingCart& cart;
public:
    DatabaseSaver(const ShoppingCart& cart) : cart(cart) {}

    void addToDB() {
        cout << "Saving products to database..." << endl;
    }
};
int main(){
    ShoppingCart cart;
    cart.addProduct(Product("Product 1", 10.0));
    cart.addProduct(Product("Product 2", 20.0));

    InvoicePrinter printer(cart);
    printer.printInvoice();

    DatabaseSaver dbSaver(cart);
    dbSaver.addToDB();

    return 0;
}
