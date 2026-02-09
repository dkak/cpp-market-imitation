#include "../include/IOrderBook.h"
#include "../include/Market.h"
#include "../include/Order.h"

#include <chrono>
#include <iostream>
#include <list>

Market::Market(std::unique_ptr<IOrderBook> order_book){
    this->order_book=std::move(order_book);
}

int Market::getOrdersSize(){
    return this->order_book->getOrdersSize();
}

std::unordered_map<int,OrderMatch> Market::getMatchedOrders(){
    return this->matched_orders;
}

void Market::addMatchedOrder(OrderMatch matched_order){
    this->matched_orders.emplace(matched_order.getId(),matched_order);
}

void Market::processIncomingOrder(Order &order){
    
    while(order.getQuantity()>0){
        Order* resting_order=order_book->getBestMatch(order);
        if(resting_order==nullptr) break;
        this->completeTransaction(order,*resting_order);
    }

    if(order.getQuantity()>0) this->order_book->addOrder(order);
}

void Market::completeTransaction(Order &incoming_order,Order &resting_order){

    int traded_quantity=std::min(incoming_order.getQuantity(),resting_order.getQuantity());
    incoming_order.reduceQuantity(traded_quantity);
    resting_order.reduceQuantity(traded_quantity);

    OrderMatch order_match((static_cast<int>(this->matched_orders.size()))+1,incoming_order,resting_order,traded_quantity);
    this->addMatchedOrder(order_match);

    if(resting_order.getQuantity()==0) order_book->removeOrder(resting_order);
}