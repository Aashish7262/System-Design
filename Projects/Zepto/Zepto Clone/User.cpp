#include "User.h"

User::User(int userId, string name, double x, double y) {
    this->userId = userId;
    this->name = name;
    this->x = x;
    this->y = y;
}

int User::getUserId() const {
    return userId;
}

string User::getName() const {
    return name;
}

double User::getX() const {
    return x;
}

double User::getY() const {
    return y;
}

Cart& User::getCart() {
    return cart;
}
