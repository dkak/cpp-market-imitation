#include "ListOrderBook.h"
#include "OrderMatch.h"

#include <list>

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
        this->buy_orders.remove(order);
    }
}
        
Order ListOrderBook::getMatchedOrder(Order order){
    
    std::list<Order> pair_orders;
    if(order.getSide()==OrderType::Buy){
        pair_orders=this->sell_orders;
    }
    else{
        pair_orders=this->buy_orders;
    }
    
    for(Order &pair_order: pair_orders){
        if( // finding buyer/seller based on price
            (
                order.getSide() == OrderType::Buy && 
                order.getPrice() >= pair_order.getPrice()
            ) 
            || 
            (
                order.getSide() == OrderType::Sell && 
                order.getPrice() <= pair_order.getPrice()
            )
        )
        {
            
            if(order.getQuantity() < pair_order.getQuantity()){
                pair_order.setQuantity( 
                    pair_order.getQuantity() - order.getQuantity()
                );
                return pair_order;
            }
            else if(order.getQuantity() > pair_order.getQuantity()){
                order.setQuantity(
                    order.getQuantity() - pair_order.getQuantity()
                );
                removeOrder(pair_order);
                return pair_order;
            }
            else{
                removeOrder(pair_order);
                return pair_order;
            }
        }
    }
    if(order.getQuantity()>0) return order;
    return order;
}
