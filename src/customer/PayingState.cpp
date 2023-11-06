#include "PayingState.h"
#include "customer/Customer.h"

#include <iostream>

void PayingState::visit(Manager& m) {
    std::cout << "[Paying]: Give payment to manager" << std::endl;
    customer_->changeState(nullptr);
}

void PayingState::visit(Waiter& w) {
    std::cout << "[Paying]: Give payment to waiter" << std::endl;
    customer_->changeState(nullptr);
}

std::string PayingState::toString() const { return "[Paying]"; }
