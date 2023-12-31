#pragma once

#include "CustomerState.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include <string>
class PayingState : public CustomerState {
public:
    PayingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

    std::string toString() const override;

private:
    bool isReady_ = false;
};