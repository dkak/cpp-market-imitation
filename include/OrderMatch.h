#ifndef OrderMatch_H
#define OrderMatch_H

#include "Order.h"

class OrderMatch{

    private:
        Order buy_order;
        Order sell_order;
        bool fulfilled_buy_order;
        bool fulfilled_sell_order;
    public:
        OrderMatch(
            Order buy_order, 
            Order sell_order, 
            bool fulfilled_buy_order, 
            bool fulfilled_sell_order
        );
        Order getBuyOrder();
        Order getSellOrder();
        bool getFulfilledBuyOrder();
        bool getFulfilledSellOrder();
};

#endif