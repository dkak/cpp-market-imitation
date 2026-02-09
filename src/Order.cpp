#include "../include/Order.h"

#include <iostream>

Order::Order(int id,double price,int quantity,OrderType side){
    this->id=id;
    this->price=price;
    this->quantity=quantity;
    this->side=side;
}

int Order::getId(){
    return this->id;    
}

double Order::getPrice(){
    return this->price;    
}

int Order::getQuantity(){
    return this->quantity;    
}

void Order::reduceQuantity(int quantity){
    if(quantity<=this->getQuantity()){
        this->quantity-=quantity;
    }
    else{
        std::cout << "Quantity overflow!" << std::endl;
    }
}

OrderType Order::getSide(){
    return this->side;    
}