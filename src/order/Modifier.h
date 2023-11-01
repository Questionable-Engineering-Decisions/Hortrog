#pragma once

#include "Order.h"

class Modifier : public Order{
protected:
    std::unique_ptr<Order> component;
    std::string key;
    double price;
public:
    void add(std::unique_ptr<Order>) override;
    double total() override;
    std::string toJson() override;
    explicit Modifier(std::unique_ptr<Order> component);
};