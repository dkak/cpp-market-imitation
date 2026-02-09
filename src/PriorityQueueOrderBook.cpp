#include "PriorityQueueOrderBook.h"
#include "OrderMatch.h"

#include <queue>

int PriorityQueueOrderBook::getOrdersSize(){
    return this->buy_orders.size()+this->sell_orders.size();
}

void PriorityQueueOrderBook::addOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        this->buy_orders.emplace(order.getPrice(),order);
    }else{
        this->sell_orders.emplace(order.getPrice(),order);
    }
}

void PriorityQueueOrderBook::removeOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        this->buy_orders.pop();
    }else{
        this->sell_orders.pop();
    }
}
        
Order* PriorityQueueOrderBook::getBestMatch(Order &order){
    
    if(order.getSide()==OrderType::Buy){
        if (sell_orders.empty()) return nullptr;

        Order& pair_order = sell_orders.top();
        if (order.getPrice() >= pair_order.getPrice()) {
            return &pair_order;
        }
    }
    else{
        if (buy_orders.empty()) return nullptr;

        Order& pair_order = buy_orders.top();
        if (order.getPrice() <= pair_order.getPrice()) {
            return &pair_order;
        }
    }

    return nullptr;
}