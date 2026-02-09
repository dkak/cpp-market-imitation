#ifndef IORDERBOOK_H
#define IORDERBOOK_H

#include "Order.h"

#include <optional>

class IOrderBook{

    public:
        // Virtual destructor is MANDATORY for interfaces to prevent memory leaks
        virtual ~IOrderBook()=default;
        
        // Pure virtual functions
        virtual int getOrdersSize()=0;

        virtual void addOrder(Order order)=0;

        virtual void removeOrder(Order order)=0;
        
        virtual Order* getBestMatch(Order &order) = 0;
};

#endif