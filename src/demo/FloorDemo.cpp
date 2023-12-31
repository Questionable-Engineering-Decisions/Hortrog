#include "FloorDemo.h"
#include "core/util.h"

#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "floor/CustomerIterator.h"
#include "floor/Table.h"
#include "floor/TableComponent.h"
#include "floor/TableGroup.h"

#include <algorithm>
#include <errno.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>

FloorDemo::FloorDemo(Floor& floor, Menu& menu, Kitchen* k)
    : floor_(floor), menu_(menu), kitchen_(k) {}

void FloorDemo::gameLoop() {
    // Draw tables
    // std::cout << util::CLEAR_SCREEN << util::HOME << std::endl;
    std::cout << "\n--- THE FLOOR ---" << std::endl;
    std::cout << floor_.toString() << std::endl;
    std::cout << "---------------------------" << std::endl;

    // Chose next action
    if (mainOptions_.execute()) {
        setRunning(false);
    }
}

void FloorDemo::init() {
    menu_.loadFromFile("menu_items.json");

    mainOptions_.addCommand("Add Table", [this]() { addTable(); });
    mainOptions_.addCommand("Add Waiter", [this]() { addStaff(); });
    mainOptions_.addCommand("Add Customers", [this]() { addCustomers(); });
    mainOptions_.addCommand("Visit tables", [this]() { visitCustomers(); });
    mainOptions_.setPrompt("Choose an option (-1 to quit): ");
    mainOptions_.setExitCode(-1);
}

void FloorDemo::cleanup() {}

void FloorDemo::addTable() {
    int capacity;
    do {
        capacity = util::input("Number of seats: ");
    } while (capacity < 1);

    std::cout << "Table ID: " << floor_.addTable(capacity);
}
void FloorDemo::addCustomers() {
    if (floor_.getFloorStaffSize() < 1) {
        util::error("No staff available to serve customers");
        return;
    }

    // Request table from floor
    int numCustomers = util::input("Number of customers: ");
    Table* table = floor_.requestSeating(numCustomers);
    if (!table) {
        util::error("Cannot accomadate that many customers");
        return;
    }

    // Add customers to table
    std::string line;
    for (int i = 0; i < numCustomers; i++) {
        std::cout << "Customer name: ";
        std::getline(std::cin, line);
        Customer* c = new Customer(line, 100);
        table->seatCustomer(c);
    }

    // Assign waiter to table
    Waiter* waiter = nullptr;
    int opt = -1;
    do {
        int opt = util::input("Enter Waiter Number: ");
        waiter = floor_.getWaiter(opt);
        if (!waiter) {
            std::cout << "Waiter not found" << std::endl;
        }
    } while (!waiter);
    waiter->assignTable(table);
}

void FloorDemo::addStaff() {
    floor_.addStaff(new Waiter(&menu_, kitchen_, &pointOfSales_));
}

void FloorDemo::visitCustomers() {
    FloorStaff* staff = nullptr;
    int opt = -1;
    do {
        opt = util::input("Enter Staff Number: ");
        staff = floor_.getFloorStaff(opt);
        if (!staff) {
            std::cout << "Staff not found" << std::endl;
        }
    } while (!staff && opt != -1);
    if (opt == -1) return;

    staff->visitTables();
    std::cout << "Visited tables" << std::endl;
    std::cout << kitchen_->toString() << std::endl;

}