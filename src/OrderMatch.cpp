#include "OrderMatch.h"

OrderMatch::OrderMatch(
    Order incoming_order, 
    Order resting_order, 
    int traded_quantity
)
{
    this->incoming_order=incoming_order;
    this->resting_order=resting_order;
    this->traded_quantity=traded_quantity;
}

Order OrderMatch::getIncomingOrder(){
    return this->incoming_order;
}

Order OrderMatch::getRestingOrder(){
    return this->resting_order;
}

int OrderMatch::getTradedQuantity(){
    return this->traded_quantity;
}
