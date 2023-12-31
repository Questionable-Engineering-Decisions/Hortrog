#include "PointOfSales.h"
#include "billing/CardPayment.h"
#include "billing/CashPayment.h"
#include "order/Receipt.h"
#include <iostream>

//
// void PointOfSales::registerOrder(Order* order){
//    orders.push_back(order);
//}
//
//
// void PointOfSales::printBill(int tblId) {
//    std::cout << "========================================" << std::endl;
//    std::cout << "            BILL" << std::endl;
//    std::cout << "========================================" << std::endl;
//    std::cout << "Order items:" << std::endl;
//    float total=0;
//    Receipt* rec=new Receipt();
//    std::vector<std::pair<std::string, double>> items;
//    for (const auto& order : orders) {
//        if(order->getTblId()==tblId){
//            rec->generateOrders(order);
//            items=rec->getOrders();
//            for (const auto& item : items) {
//                total+=item.second;
//                std::cout << "- " << item.first << ": R" << item.second <<
//                std::endl;
//            }
//        }
//    }
//    Payment* payment=new Payment(tblId,total);
//    payments.push_back(payment);
//    std::cout << "Total: R" << total << std::endl;
//    std::cout << "========================================" << std::endl;
//}
//
// bool PointOfSales::isPaymentSettled(int tblId){
//    for (const auto& payment : payments) {
//        if(payment->gettableId()==tblId){
//            if(payment->getAmountOfPayment()>0){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
// bool PointOfSales::makeCashPayment(int tblId, float amount){
//    for (const auto& payment : payments) {
//        if(payment->gettableId()==tblId){
//            CashPayment* cPayment= new CashPayment(payment,amount);
//            cPayment->paymentDetails();
//            payment->setAmountOfPayment(payment->getAmountOfPayment()-amount);
//            if(isPaymentSettled(tblId)){
//                std::cout<<"The bill has been settled"<<std::endl;
//                return true;
//            }
//            else{
//                std::cout<<"The bill has not been settled"<<std::endl;
//                std::cout<<"an amount of "<<payment->getAmountOfPayment()<<"
//                remains"<<std::endl; return false;
//            }
//        }
//        std::cout<<"A bill does not exist for this table"<<std::endl;
//        return false;
//    }
//    std::cout<<"No bills exist"<<std::endl;
//        return false;
//}

// bool PointOfSales::makeCardPayment(int tblId, float amount, const
// std::string& nameOnCard, const std::string& expirationDate, const
// std::string& creditCardNumber){ for (const auto& payment : payments) {
//         if(payment->gettableId()==tblId){
//             CardPayment* cPayment= new
//             CardPayment(payment,amount,nameOnCard,expirationDate,creditCardNumber);
//             cPayment->paymentDetails();
//             payment->setAmountOfPayment(payment->getAmountOfPayment()-amount);
//             if(isPaymentSettled(tblId)){
//                 std::cout<<"The bill has been settled"<<std::endl;
//                 return true;
//             }
//             else{
//                 std::cout<<"The bill has not been settled"<<std::endl;
//                 std::cout<<"an amount of "<<payment->getAmountOfPayment()<<"
//                 remains"<<std::endl; return false;
//             }
//         }
//         std::cout<<"A bill does not exist for this table"<<std::endl;
//         return false;
//     }
//     std::cout<<"No bills exist"<<std::endl;
//         return false;
// }

std::vector<Receipt> PointOfSales::getReceipt(
    POSStrategy* strategy, uint32_t tableId) {
    std::vector<Order*> tableOrders;
    for (auto order : orders_) {
        if (order->getTblId() == tableId) {
            tableOrders.push_back(order);
        }
    }
    return strategy->getReceipts(tableOrders);
}
