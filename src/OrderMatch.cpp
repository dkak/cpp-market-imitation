#include "OrderMatch.h"

OrderMatch::OrderMatch(
    Order first_order, 
    Order second_order, 
    bool fulfilled_first_order, 
    bool fulfilled_second_order
)
{
    this->first_order=first_order;
    this->second_order=second_order;
    this->fulfilled_first_order=fulfilled_first_order;
    this->fulfilled_second_order=fulfilled_second_order;
}

Order OrderMatch::getFirstOrder(){
    return this->first_order;
}

Order OrderMatch::getSecondOrder(){
    return this->second_order;
}

bool OrderMatch::getFulfilledFirstOrder(){
    return this->fulfilled_first_order;
}

bool OrderMatch::getFulfilledSecondOrder(){
    return this->fulfilled_second_order;
}
