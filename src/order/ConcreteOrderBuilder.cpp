#include "order/ConcreteOrderBuilder.h"
#include <iostream>
#include <memory>
#include <string>

void ConcreteOrderBuilder::begin(uint32_t tblId) {
    this->tempOrder = std::vector<std::unique_ptr<Order>>();
    this->tblId_ = tblId;
}

bool ConcreteOrderBuilder::addItem(
    const std::string& key, const std::string& customerName) {
    const MenuItem* item = menu_->getMenuItem(key);
    if (!item) {
        return false;
    }
    // this->customerNames_.emplace_back(customerName);
    this->tempOrder.emplace_back(std::make_unique<OrderItem>(item));
    this->tempOrder.back()->setCustomer(customerName);
    this->tempOrder.back()->setTblId(this->tblId_);
    return true;
}

bool ConcreteOrderBuilder::addModifier(const std::string& key) {
    // Return false if the vector is empty
    if (this->tempOrder.empty()) {
        return false;
    }
    // Save then remove the  last OrderItem in the vector
    std::unique_ptr<Order> lastOrder = std::move(this->tempOrder.back());
    this->tempOrder.pop_back();
    // Create a Modifier from the last OrderItem
    std::unique_ptr<Order> modifier =
        std::make_unique<Modifier>(std::move(lastOrder));
    // Add the modifier to the vector
    this->tempOrder.emplace_back(std::move(modifier));
    return true;
}

ConcreteOrderBuilder::ConcreteOrderBuilder(const Menu* menu)
    : OrderBuilder(), menu_(menu) {}

std::string ConcreteOrderBuilder::getResult() {
    // return empty string if the vector is empty
    if (this->tempOrder.empty()) {
        return "{}\n";
    }

    // Create a new OrderComposite
    this->order = new OrderComposite();
    // Add all the Orders in the vector to the OrderComposite
    for (auto& order : this->tempOrder) {
        this->order->add(std::move(order));
    }
    // Return the OrderComposite as a JSON string
    this->order->setTblId(this->tblId_);
    return this->order->toJson();
}
