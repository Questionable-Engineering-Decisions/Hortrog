#include "OrderingState.h"
#include "customer/WaitingState.h"
#include "floor/Table.h"
#include "menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

void OrderingState::visit(Manager& m) {
    if (readyTimer_.expired()) {
        std::vector<std::string> complaints = {
            "We have been waiting for a long time",
            "Slow service im starving",
            "Dirty utensils and where is the food",
            "Noisy atmosphere cant even get a drink",
            "can you please call a waiter so we can order",
            "I have been waiting for a long time",
            "Can i Get any Hungrier???  ",
        };
        srand(time(0));
        int randomIndex = rand() % complaints.size();
        m.lodgeComplaint(complaints[randomIndex]);
        this->customer_->setHappiness(this->customer_->getHappiness() - 5);
        // request a waiter
    } else {
        std::cout << "Manager talked to a cutomer" << std::endl;
        this->customer_->setHappiness(this->customer_->getHappiness() + 5);
    }
}
void OrderingState::visit(Waiter& w) {
    OrderBuilder* TableOrder = w.getOrderBuilder();
    const Menu* menu = TableOrder->getMenu();
    std::vector<std::string> allItems = menu->getAllKeys();
    srand(time(0));
    int randomNumber = std::rand() % allItems.size();
    if (readyTimer_.expired()) {
        std::string item = allItems[randomNumber];
        TableOrder->addItem(item, customer_->getName());
        int randomNumber = std::rand() % 100;
        if (std::rand() % 4 == 0) {
            std::vector<std::string> modifierNames;
            const MenuItem* menuItem = menu->getMenuItem(item);
            modifierNames = menuItem->supportedModifiers();
            if (modifierNames.size() != 0) {
                int randomIndex = std::rand() % modifierNames.size();
                TableOrder->addModifier(modifierNames[randomIndex]);
                std::cout << customer_->toString() << ": I ordered " << item
                          << " with " << modifierNames[randomIndex]
                          << std::endl;
                this->customer_->setHappiness(
                    this->customer_->getHappiness() + 5);
                customer_->changeState(new WaitingState(customer_));
            }
            w.giveTokitchen();
        } else {
            std::cout << customer_->toString() << ": I ordered " << item
                      << std::endl;
            this->customer_->setHappiness(this->customer_->getHappiness() + 5);
            customer_->changeState(new WaitingState(customer_));
            w.giveTokitchen();
        }
    } else {
        std::cout << customer_->toString() << ": Not ready to order"
                  << std::endl;
    }
}
void OrderingState::update(float dt) { readyTimer_.update(dt); }

std::string OrderingState::toString() const {
    std::stringstream ss;
    ss << "[Ordering] ";
    if (readyTimer_.expired()) {
        ss << "Ready to order";
    } else {
        ss << std::setprecision(5) << readyTimer_.remaining();
    }
    return ss.str();
}
