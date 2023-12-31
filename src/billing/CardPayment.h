#pragma once

#include <string>
#include "Payment.h"

using namespace std;

class CardPayment : public Payment {
public:
    CardPayment();
    CardPayment(Payment* payment, float amount, const std::string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber);
    const string& getNameOnCard() const;
    const string& getExpirationDate() const;
    const string& getCreditCardNumber() const;
    void setNameOnCard(const std::string& nameOnCard);
    void setExpirationDate(const std::string& expirationDate);
    void setCreditCardNumber(const std::string& creditCardNumber);
    void paymentDetails() const override;
    float getCardPaid() const;
    void setCardPaid(float cardPaid);
private:
    string nameOnCard;
    string expirationDate;
    string creditCardNumber;
    float cardPaid;
};