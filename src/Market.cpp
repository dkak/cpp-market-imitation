#include "../include/Market.h"
#include "../include/Order.h"

#include <iostream>
#include <chrono>

void Market::addOrder(Order &order){
    if(order.getSide()==OrderType::Buy){      
        if(!findOrder(order,sell_orders)) this->buy_orders.push_back(order);
    }else if(order.getSide()==OrderType::Sell){
        if(!findOrder(order,buy_orders)) this->sell_orders.push_back(order);
    }else{
        std::cout << "Invalid order! It is skipped." << std::endl;
    }
}

void Market::addMatchedOrder(OrderMatch matched_order){
    this->matched_orders.push_back(matched_order);
}

void Market::removeOrder(Order order){
    if(order.getSide()==OrderType::Buy){
        this->buy_orders.remove(order);
    }
    else{
        this->sell_orders.remove(order);
    }
}

bool Market::findOrder(Order &order,std::list<Order> &pair_orders){

    // auto start = std::chrono::high_resolution_clock::now(); // Start timer
    for(Order &pair_order: pair_orders){
        if(
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
            // auto end = std::chrono::high_resolution_clock::now(); // Stop timer
            // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            // std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
            if(order.getQuantity() < pair_order.getQuantity()){
                pair_order.setQuantity( 
                    pair_order.getQuantity() - order.getQuantity()
                );
                OrderMatch matched_order(order,pair_order,true,false);
                addMatchedOrder(matched_order);
                return true;
            }
            else if(order.getQuantity() > pair_order.getQuantity()){
                order.setQuantity(
                    order.getQuantity() - pair_order.getQuantity()
                );
                OrderMatch matched_order(order,pair_order,false,true);
                addMatchedOrder(matched_order);
                removeOrder(pair_order);
            }
            else{
                OrderMatch matched_order(order,pair_order,true,true);
                addMatchedOrder(matched_order);
                removeOrder(pair_order);
                return true;
            }
        }
    }
    if(order.getQuantity()>0) return false;
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