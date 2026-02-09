#include "ListOrderBook.h"
#include "OrderMatch.h"

#include <list>
#include <optional>

int ListOrderBook::getOrdersSize(){
    return this->buy_orders.size()+this->sell_orders.size();
}

void ListOrderBook::addOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        this->buy_orders.push_back(order);
    }else{
        this->sell_orders.push_back(order);
    }
}

void ListOrderBook::removeOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        this->buy_orders.remove(order);
    }else{
        this->sell_orders.remove(order);
    }
}
        
Order* ListOrderBook::getBestMatch(Order &order){
    
    // We use a pointer here. NO orders are copied!
    std::list<Order>* pair_orders;
    if(order.getSide()==OrderType::Buy){
        pair_orders=&this->sell_orders;
    }
    else{
        pair_orders=&this->buy_orders;
    }
    
    for(Order &pair_order: *pair_orders){
        // finding buyer/seller based on price
        if( 
            (   // buyer with matching or higher price
                order.getSide() == OrderType::Buy && 
                order.getPrice() >= pair_order.getPrice()
            ) 
            || 
            (   // seller with matching or lower price
                order.getSide() == OrderType::Sell && 
                order.getPrice() <= pair_order.getPrice()
            )
        )
        {
            return &pair_order;
        }
    }
    return nullptr;
}
