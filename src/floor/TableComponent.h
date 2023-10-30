#pragma once

#include "floor/Customer.h"
#include "floor/Table.h"
#include <vector>

class TableComponent : public Table {
public:
    TableComponent(uint32_t id, int capacity) : id_(id), capacity_(capacity) {}

    void buildOrder(OrderBuilder& builder) override;
    TableGroup* merge(Table* table) override;
    std::vector<TableComponent*> split() override;
    bool addCustomer(Customer* customer) override;

    bool isEmpty() const override;
    int getCapacity() const override;
    uint32_t id() const override;

    std::string toString() const override;

private:
    int id_;
    int capacity_;
    std::vector<Customer*> customers_;
};