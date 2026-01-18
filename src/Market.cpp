#include "../include/IOrderBook.h"
#include "../include/Market.h"
#include "../include/Order.h"

#include <chrono>
#include <iostream>

Market::Market(std::unique_ptr<IOrderBook> order_book){
    this->order_book=order_book;
}

void Market::processIncomingOrder(const Order order){
    Order pair_order=order_book->getMatchedOrder(order);
    if(pair_order==NULL){
        
    }
}

void Market::addMatchedOrder(OrderMatch matched_order){
    this->matched_orders.push_back(matched_order);
}