#include <iostream>
using namespace std;

class User {
private:
    string name;
    string email;
    int age;
    string phone;

public:
    User(string name, string email, int age, string phone) {
        this->name = name;
        this->email = email;
        this->age = age;
        this->phone = phone;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Age: " << age << endl;
        cout << "Phone: " << phone << endl;
    }
};

class UserBuilder {
private:
    string name;
    string email;
    int age = 0;
    string phone;

public:
    UserBuilder& setName(string name) {
        this->name = name;
        return *this;
    }

    UserBuilder& setEmail(string email) {
        this->email = email;
        return *this;
    }

    UserBuilder& setAge(int age) {
        this->age = age;
        return *this;
    }

    UserBuilder& setPhone(string phone) {
        this->phone = phone;
        return *this;
    }

    User build() {
        return User(name, email, age, phone);
    }
};

int main() {
    User user = UserBuilder()
                    .setName("Aashish")
                    .setEmail("aashish@gmail.com")
                    .setAge(19)
                    .setPhone("7262836591")
                    .build();

    user.display();

    return 0;
}