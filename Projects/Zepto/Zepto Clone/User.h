#ifndef USER_H
#define USER_H

#include "Cart.h"
#include <string>

using namespace std;

class User {
private:
    int userId;
    string name;
    double x;
    double y;
    Cart cart;

public:
    User(int userId, string name, double x, double y);

    int getUserId() const;
    string getName() const;
    double getX() const;
    double getY() const;

    Cart& getCart();
};

#endif
