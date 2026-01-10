#include "../include/Order.h"

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

void Order::setPrice(long price){
    this->price=price;
}

int Order::getQuantity(){
    return this->quantity;    
}

void Order::setQuantity(int quantity){
    this->quantity=quantity;
}

OrderType Order::getSide(){
    return this->side;    
}