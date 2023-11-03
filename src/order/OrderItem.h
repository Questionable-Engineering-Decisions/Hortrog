#pragma once

#include "Order.h"

class OrderItem : public Order {
protected:
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

private:
    std::string id;
    double price;

public:
    std::string toJson() override;
    double total() override;
    void add(std::unique_ptr<Order>) override;
    OrderItem(std::string id, double price);
    void setPrice(double price);
    [[nodiscard]] double getPrice() const;
    std::string getId();
};