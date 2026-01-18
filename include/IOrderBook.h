#ifndef IORDERBOOK_H
#define IORDERBOOK_H

#include "Order.h"

class IOrderBook{

    public:
        // Virtual destructor is MANDATORY for interfaces to prevent memory leaks
        virtual ~IOrderBook()=default;
        
        // Pure virtual functions
        virtual void addOrder(Order order)=0;

        virtual void removeOrder(Order order)=0;
        
        virtual Order getMatchedOrder(Order order) = 0;
};

#endif