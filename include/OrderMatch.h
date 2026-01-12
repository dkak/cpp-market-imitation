#ifndef OrderMatch_H
#define OrderMatch_H

#include "Order.h"

class OrderMatch{

    private:
        Order first_order;
        Order second_order;
        bool fulfilled_first_order;
        bool fulfilled_second_order;
    public:
        OrderMatch(
            Order first_order, 
            Order second_order, 
            bool fulfilled_first_order, 
            bool fulfilled_second_order
        );
        Order getFirstOrder();
        Order getSecondOrder();
        bool getFulfilledFirstOrder();
        bool getFulfilledSecondOrder();
};

#endif