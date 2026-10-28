#ifndef DELIVERY_PARTNER_H
#define DELIVERY_PARTNER_H

#include <string>

using namespace std;

class DeliveryPartner {
private:
    int partnerId;
    string name;
    bool available;

public:
    DeliveryPartner(int partnerId, string name);

    int getPartnerId() const;
    string getName() const;

    bool isAvailable() const;
    void setAvailable(bool available);
};

#endif
