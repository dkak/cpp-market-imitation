#include "OrderMatch.h"

OrderMatch::OrderMatch(
    Order buy_order, 
    Order sell_order, 
    bool fulfilled_buy_order, 
    bool fulfilled_sell_order
)
{
    this->buy_order=buy_order;
    this->sell_order=sell_order;
    this->fulfilled_buy_order=fulfilled_buy_order;
    this->fulfilled_sell_order=fulfilled_sell_order;
}

Order OrderMatch::getBuyOrder(){
    return this->buy_order;
}

Order OrderMatch::getSellOrder(){
    return this->sell_order;
}

bool OrderMatch::getFulfilledBuyOrder(){
    return this->fulfilled_buy_order;
}

bool OrderMatch::getFulfilledSellOrder(){
    return this->fulfilled_sell_order;
}
