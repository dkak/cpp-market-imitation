#include "VectorOrderBook.h"
#include "OrderMatch.h"

#include <vector>
#include <algorithm>

int VectorOrderBook::getOrdersSize(){
    return this->buy_orders.size()+this->sell_orders.size();
}

void VectorOrderBook::addOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        this->buy_orders.push_back(order);
    }else{
        this->sell_orders.push_back(order);
    }
}

void VectorOrderBook::removeOrder(Order order){
    
    // We use a pointer here. NO orders are copied!
    std::vector<Order>* same_type_orders;
    if(order.getSide()==OrderType::Buy){
        same_type_orders=&this->buy_orders;
    }
    else{
        same_type_orders=&this->sell_orders;
    }
    auto it = std::find(same_type_orders->begin(), same_type_orders->end(),order);
    if(it != same_type_orders->end()) {
        // The "Swap and Pop" Trick (The Efficiency Pro-Move)
        std::swap(*it , same_type_orders->back());
        same_type_orders->pop_back();
    }
}
        
Order* VectorOrderBook::getBestMatch(Order &order){
    
    // We use a pointer here. NO orders are copied!
    std::vector<Order>* pair_orders;
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
