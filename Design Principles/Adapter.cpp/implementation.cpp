#include <iostream>
using namespace std;

class PaymentProcessor {
public:
    virtual void pay() = 0;
    virtual ~PaymentProcessor() = default;
};

class Razorpay {
public:
    void makePayment() {
        cout << "Payment through Razorpay" << endl;
    }
};

class RazorpayAdapter : public PaymentProcessor {
private:
    Razorpay razorpay;

public:
    void pay() override {
        razorpay.makePayment();
    }
};

int main() {
    PaymentProcessor* payment = new RazorpayAdapter();

    payment->pay();

    delete payment;

    return 0;
}