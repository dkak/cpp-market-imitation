#include "../include/Market.h"
#include "../include/Order.h"

#include <iostream>
#include <chrono>

void Market::addOrder(Order &order){
    if(order.getSide()==OrderType::Buy){      
        if(!findBuyOrder(order)) this->buy_orders.push_back(order);
    }else if(order.getSide()==OrderType::Sell){
        if(!findSellOrder(order)) this->sell_orders.push_back(order);
    }else{
        std::cout << "Invalid order! It is skipped." << std::endl;
    }
}

void Market::addMatchedOrder(OrderMatch matched_order){
    this->matched_orders.push_back(matched_order);
}

void Market::removeBuyOrder(Order buy_order){
    this->buy_orders.remove(buy_order);
}

void Market::removeSellOrder(Order sell_order){
    this->sell_orders.remove(sell_order);
}

bool Market::findBuyOrder(Order &buy_order){
    for(Order &sell_order: sell_orders){
        if(sell_order.getPrice()<=buy_order.getPrice()){

            if(sell_order.getQuantity()>buy_order.getQuantity()){
                sell_order.setQuantity( 
                    sell_order.getQuantity() - buy_order.getQuantity()
                );
                OrderMatch matched_order(buy_order,sell_order,true,false);
                addMatchedOrder(matched_order);
                return true;
            }
            else if(sell_order.getQuantity()<buy_order.getQuantity()){
                buy_order.setQuantity( 
                    buy_order.getQuantity() - sell_order.getQuantity()
                );
                OrderMatch matched_order(buy_order,sell_order,false,true);
                addMatchedOrder(matched_order);
                removeSellOrder(sell_order);
            }
            else{
                OrderMatch matched_order(buy_order,sell_order,true,true);
                addMatchedOrder(matched_order);
                removeSellOrder(sell_order);
                return true;
            }
        }
    }
    if(buy_order.getQuantity()>0) return false;
    return true;
}

bool Market::findSellOrder(Order &sell_order){

    // auto start = std::chrono::high_resolution_clock::now();             // Start timer
    
    for(Order &buy_order: buy_orders){
        if(sell_order.getPrice()<=buy_order.getPrice()){

            // auto end = std::chrono::high_resolution_clock::now();       // Stop timer
            // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            // std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
            
            if(buy_order.getQuantity()>sell_order.getQuantity()){
                buy_order.setQuantity( 
                    buy_order.getQuantity() - sell_order.getQuantity()
                );
                OrderMatch matched_order(buy_order,sell_order,false,true);
                addMatchedOrder(matched_order);
                return true;
            }
            else if(buy_order.getQuantity()<sell_order.getQuantity()){
                sell_order.setQuantity( 
                    sell_order.getQuantity() - buy_order.getQuantity()
                );
                OrderMatch matched_order(buy_order,sell_order,true,false);
                addMatchedOrder(matched_order);
                removeBuyOrder(buy_order);
            }
            else{
                OrderMatch matched_order(buy_order,sell_order,true,true);
                addMatchedOrder(matched_order);
                removeBuyOrder(buy_order);
                return true;
            }
        }
    }
    if(sell_order.getQuantity()>0) return false;
    return true;
}

std::list<Order> Market::getBuyOrders(){
    return this->buy_orders;
}

std::list<Order> Market::getSellOrders(){
    return this->sell_orders;
}

std::list<OrderMatch> Market::getMatchedOrders(){
    return this->matched_orders;
}

int Market::getBuyOrdersSize(){
    return this->buy_orders.size();
}

int Market::getSellOrdersSize(){
    return this->sell_orders.size();
}