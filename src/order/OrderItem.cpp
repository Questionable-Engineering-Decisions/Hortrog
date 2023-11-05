#include "OrderItem.h"
#include "menu/Menu.h"

OrderItem::OrderItem(MenuItem* item) : item_(item) {}

std::string OrderItem::toJson() {
    std::string ret = "{\"name\": \"" + item_->getName() + "\",";
    ret += "\"price\": " + std::to_string(item_->getPrice()) + "}";
    return ret;
}

double OrderItem::total() { return item_->getPrice(); }
void OrderItem::add(std::unique_ptr<Order>) {}

std::string OrderItem::getId() { return item_->getName(); }
std::vector<std::pair<std::string, double>>
OrderItem::generateReceiptOrderList() {
    std::vector<std::pair<std::string, double>> returnVec;
    returnVec.emplace_back(item_->getName(), item_->getPrice());
    return returnVec;
}
