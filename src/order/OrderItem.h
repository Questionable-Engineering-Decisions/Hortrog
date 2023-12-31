// ORDERITEMH
#pragma once

#include "Order.h"
#include "menu/Menu.h"

class OrderItem : public Order {

public:
    OrderItem(const MenuItem* item);
    std::vector<Order*> getChildren() override {
        std::vector<Order*> ret;
        return ret;
    };
    std::string toJson() override;
    double total() override;
    void add(std::unique_ptr<Order>) override;
    std::string getId() override;
    bool checkForCustomer(std::string customerName) override;
    bool checkForDupe(std::string customerName,
        std::vector<const MenuItem*> menuItems) override;
    std::vector<const MenuItem*> getAllMenuItems() override;

    std::string toString() const override;

protected:
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

private:
    const MenuItem* item_;
    // MenuItem* item_;
};