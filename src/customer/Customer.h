#pragma once

class OrderBuilder;

#include "CustomerState.h"
#include "subsystem/Meals/Meal.h"

#include <memory>
#include <string>
class FloorStaff;
class Customer {
public:
    /**
     * @brief Construct a new Customer object
     *
     * @param name
     * @param happiness
     */
    Customer(const std::string& name, float happiness);
    /**
     * @brief This is the function that allows the customer to interact with int
     * the Vistor pattern
     *
     * @param staff the staff that the customer is interacting with
     */
    void interact(FloorStaff& staff);
    /**
     * @brief This is the function that allows the customer to update in the
     * Vistor pattern
     *
     * @param dt the time that has passed
     */
    void update(float dt);
    /**
     * @brief This is the function that allows the customer to change state in
     * the Vistor pattern
     *
     * @param state the state that the customer is changing to
     */
    void changeState(CustomerState* state);
    /**
     * @brief This is the function that allows the customer to receive a meal
     *
     * @param meal the meal that the customer is receiving
     */
    inline const std::string& getName() const { return name_; }
    /**
     * @brief This is the function that allows the customer to receive a meal
     *
     * @param meal the meal that the customer is receiving
     */
    inline float getHappiness() const { return happiness_; }
    /**
     * @brief This is the function that allows the customer to receive a meal
     *
     * @param meal the meal that the customer is receiving
     */
    inline void setHappiness(float happiness) { happiness_ = happiness; }
    /**
     * @brief This is the function that allows the customer to receive a meal
     *
     * @param meal the meal that the customer is receiving
     */
    inline Meal* getReceivedMeal() const { return receivedMeal; }
    /**
     * @brief This is the function that allows the customer to receive a meal
     *
     * @param meal the meal that the customer is receiving
     */
    void receiveMeal(Meal* meal);

    std::string toString() const;

private:
    /**
     * @brief The state of the customer
     */
    std::unique_ptr<CustomerState> state_;
    /**
     * @brief The name of the customer
     */
    std::string name_;
    /**
     * @brief The happiness of the customer
     */
    float happiness_;
    /**
     * @brief The meal that the customer has received
     */
    Meal* receivedMeal;
};