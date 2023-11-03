#pragma once

#include <memory>
#include <string>
#include <vector>

class Order {
private:
    std::string customer_;

public:
    virtual void add(std::unique_ptr<Order>) = 0;
    virtual std::string toJson() = 0;
    virtual double total() = 0;
    virtual void setPrice(double) = 0;
    virtual double getPrice() = 0;
    virtual std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() = 0;
    virtual std::string getId() = 0;
};
