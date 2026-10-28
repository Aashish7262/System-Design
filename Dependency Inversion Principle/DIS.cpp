#include <iostream>
using namespace std;

class Database {
public:
    virtual void save() = 0;
    virtual ~Database() = default;
};

class MySQLDatabase : public Database {
public:
    void save() override {
        cout << "Saving to MySQL" << endl;
    }
};

class MongoDatabase : public Database {
public:
    void save() override {
        cout << "Saving to MongoDB" << endl;
    }
};

class UserService {
private:
    Database* database;

public:
    UserService(Database* database) {
        this->database = database;
    }

    void createUser() {
        database->save();
    }
};

int main() {

    MySQLDatabase mysql;

    UserService service(&mysql);

    service.createUser();

    return 0;
}