#include "DeliveryPartner.h"

DeliveryPartner::DeliveryPartner(int partnerId, string name) {
    this->partnerId = partnerId;
    this->name = name;
    this->available = true;
}

int DeliveryPartner::getPartnerId() const {
    return partnerId;
}

string DeliveryPartner::getName() const {
    return name;
}

bool DeliveryPartner::isAvailable() const {
    return available;
}

void DeliveryPartner::setAvailable(bool available) {
    this->available = available;
}
