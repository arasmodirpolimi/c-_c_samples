#include <iostream>
#include <string>
using namespace std;

// Strategy Interface: Payment Method
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0; // Abstract method for payment
    virtual ~PaymentStrategy() {}
};

// Concrete Strategy: Credit Card Payment
class CreditCardPayment : public PaymentStrategy {
private:
    string cardNumber;
public:
    CreditCardPayment(const string& cardNumber) : cardNumber(cardNumber) {}
    void pay(int amount) override {
        cout << "Paid $" << amount << " using Credit Card (Card Number: " << cardNumber << ")" << endl;
    }
};

// Concrete Strategy: PayPal Payment
class PayPalPayment : public PaymentStrategy {
private:
    string email;
public:
    PayPalPayment(const string& email) : email(email) {}
    void pay(int amount) override {
        cout << "Paid $" << amount << " using PayPal (Email: " << email << ")" << endl;
    }
};

// Concrete Strategy: Cryptocurrency Payment
class CryptoPayment : public PaymentStrategy {
private:
    string walletAddress;
public:
    CryptoPayment(const string& walletAddress) : walletAddress(walletAddress) {}
    void pay(int amount) override {
        cout << "Paid $" << amount << " using Cryptocurrency (Wallet: " << walletAddress << ")" << endl;
    }
};

// Context: Payment Processor
class PaymentProcessor {
private:
    PaymentStrategy* strategy; // Current payment strategy
public:
    void setStrategy(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void executePayment(int amount) {
        if (strategy) {
            strategy->pay(amount);
        } else {
            cout << "No payment strategy set!" << endl;
        }
    }
};

// Main function
int main() {
    PaymentProcessor processor;

    // Use Credit Card Payment
    CreditCardPayment creditCard("1234-5678-9012-3456");
    processor.setStrategy(&creditCard);
    processor.executePayment(100);

    // Use PayPal Payment
    PayPalPayment paypal("user@example.com");
    processor.setStrategy(&paypal);
    processor.executePayment(200);

    // Use Cryptocurrency Payment
    CryptoPayment crypto("0xabc123...");
    processor.setStrategy(&crypto);
    processor.executePayment(300);

    return 0;
}
