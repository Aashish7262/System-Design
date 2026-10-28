#include<iostream>
#include<vector>
using namespace std;
class Product{
    public:
    string name;
    double price;
    Product(string name,double price){
        this->name=name;
        this->price=price;
    }
};

class ShoppingCart {
    private :
    vector<Product> products;
    public:
    void addProduct(Product product){
        products.push_back(product);
    }
    const vector<Product>& getProducts()  {
        return products;
    }
    double calculateTotalPrice() {
        double total = 0;
        for (const auto& product : products) {
            total += product.price;
        }
        return total;
    }
    void printInvoice() {
        cout << "Invoice:" << endl;
        for (const auto& product : products) {
            cout << "Product: " << product.name << ", Price: " << product.price << endl;
        }
        cout << "Total Price: " << calculateTotalPrice() << endl;
    }
    void addToDB(){
        cout<<"Saving products to database..."<<endl;
    }

};
