#include "MultimapOrderBook.h"
#include "OrderMatch.h"

#include <map>
#include <optional>

int MultimapOrderBook::getOrdersSize(){
    return this->buy_orders.size()+this->sell_orders.size();
}

void MultimapOrderBook::addOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        this->buy_orders.emplace(order.getPrice(),order);
    }else{
        this->sell_orders.emplace(order.getPrice(),order);
    }
}

void MultimapOrderBook::removeOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        auto it=this->buy_orders.begin();
        this->buy_orders.erase(it);
    }else{
        auto it=this->sell_orders.begin();
        this->sell_orders.erase(it);
    }
}
        
Order* MultimapOrderBook::getBestMatch(Order &order){
    
    if(order.getSide()==OrderType::Buy){
        if (sell_orders.empty()) return nullptr;

        auto it = sell_orders.begin();
        if (order.getPrice() >= it->first) {
            return &(it->second);
        }
    }
    else{
        if (buy_orders.empty()) return nullptr;

        auto it = buy_orders.begin();
        if (order.getPrice() <= it->first) {
            return &(it->second);
        }
    }

    return nullptr;
}