#ifndef OrderMatch_H
#define OrderMatch_H

#include "Order.h"

class OrderMatch{

    private:
        Order incoming_order;
        Order resting_order;
        int traded_quantity;
    public:
        OrderMatch(
            Order incoming_order, 
            Order resting_order, 
            int traded_quantity
        );
        Order getIncomingOrder();
        Order getRestingOrder();
        int getTradedQuantity();
};

#endif