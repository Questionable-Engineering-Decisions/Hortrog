#include "WaitingState.h"
#include "customer/EatingState.h"
#include "customer/KarenState.h"
#include <iostream>
#include <stdlib.h>
void WaitingState::visit(Manager& m) {
    if (this->isReady_ == false) {
        return customer_->changeState(new KarenState(customer_));
    } else {
        std::cout << "[Waiting]: We're waiting for food, but it's chill"
                  << std::endl;
        this->customer_->setHappiness(this->customer_->getHappiness() + 0.5);
    }
}
void WaitingState::visit(Waiter& w) {

    if (w.getReadyMeals().size() > 0) {
        w.giveFoodToCustomer(*customer_);
        // check if customer has received their meal
        if (customer_->getReceivedMeal() != nullptr) {
            std::cout << "[Waiting]: I got my food, time to eat!" << std::endl;
            customer_->changeState(new EatingState(customer_));
        } else {
            std::cout << "[Waiting]: Where's the food at???" << std::endl;
            if (this->isReady_ == false) {
                customer_->changeState(new KarenState(customer_));
            }
        }
    } else {
        std::cout << "[Waiting]: Where's the food at???" << std::endl;
    }
}

std::string WaitingState::toString() const { return "[Waiting]"; }
