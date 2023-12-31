#include "Receipt.h"
std::vector<std::pair<std::string, double>> Receipt::getOrders() {
    return orderList_;
}
void Receipt::generateOrders(Order* order) {
    orderList_ = order->generateReceiptOrderList();
}
void Receipt::appendReceipt(Receipt* receipt) {
    for (auto pair : receipt->getOrders()) {
        orderList_.push_back(pair);
    }
}
std::string Receipt::toString() {
    std::string returnString = "";
    for (auto pair : orderList_) {
        returnString += pair.first + " : ";
        returnString += std::to_string(pair.second);
        returnString += "\n";
    }
    return returnString;
}
