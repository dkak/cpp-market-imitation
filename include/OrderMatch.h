#ifndef OrderMatch_H
#define OrderMatch_H

#include "Order.h"

class OrderMatch{

    private:
        int id;
        Order incoming_order;
        Order resting_order;
        int traded_quantity;
    public:
        OrderMatch(
            int id,
            Order incoming_order, 
            Order resting_order, 
            int traded_quantity
        );
        int getId();
        Order getIncomingOrder();
        Order getRestingOrder();
        int getTradedQuantity();
};

#endif