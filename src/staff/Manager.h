#pragma once
#include "FloorStaff.h"
#include "customer/CustomerState.h"
#include <iostream>
#include <vector>

class Floor;

/**
 * @class Manager
 * @brief This class represents a manager.
 *
 * The Manager class is a concreteElement class that inherits from the
 * FloorStaff class. It overrides the accept method from the FloorStaff class.
 */
class Manager : public FloorStaff {
public:
    Manager(const Floor* floor) : floor_(floor) {}

    /**
     * @brief Accepts a customer state.
     *
     * This function is used to accept a customer state.
     *
     * @param state The customer state to accept.
     */
    std::string getStaffType() override;
    void accept(CustomerState& state) override;
    /**
     * @brief Lodges a customer complaint.
     *
     * This function is used to lodge a customer complaint.
     *
     * @param complaint The customer's complaint.
     */
    void lodgeComplaint(const std::string& complaint);

    /**
     * @brief Gives a rating.
     *
     * This function is used to give a rating.
     *
     * @param rating The rating to give.
     */
    void giveRating(int rating);

    std::string toString() const override;

    void visitTables() override;

private:
    const Floor* floor_;
    std::vector<std::string*> complaintArray_;
    int numberOfRatings_ = 0;
    int totalRating_ = 0;
};