#pragma once
#include <vector>
#include "order/Order.h"
#include "subsystem/Meals/Meal.h"
#include "Payment.h"

class PointOfSales {
public:
    PointOfSales();
    void readyMeals(std::vector<Meal*> mealsWithOrdersIn);
    void printBill(int tblId);
    bool isPaymentSettled(int tblId);
    //the following 2 functions makes a payment and returns whether the bill is settled or not
    bool makeCashPayment(int tblId, float amount);
    bool makeCardPayment(int tblId, float amount,const std::string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber);
private:
    std::vector<Order*> orders;
    std::vector<Payment*> payments;
};