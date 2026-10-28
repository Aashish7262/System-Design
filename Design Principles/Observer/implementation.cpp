#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

class User : public Observer {
public:
    void update() override {
        cout << "New video notification!" << endl;
    }
};

class Channel {
private:
    vector<Observer*> observers;

public:
    void subscribe(Observer* observer) {
        observers.push_back(observer);
    }

    void uploadVideo() {
        cout << "New video uploaded!" << endl;

        for (auto observer : observers) {
            observer->update();
        }
    }
};

int main() {
    Channel channel;

    User user1;
    User user2;
    User user3;

    channel.subscribe(&user1);
    channel.subscribe(&user2);
    channel.subscribe(&user3);

    channel.uploadVideo();

    return 0;
}