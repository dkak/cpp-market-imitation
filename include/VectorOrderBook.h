#ifndef VECTORORDERBOOK_H
#define VECTORORDERBOOK_H

#include "IOrderBook.h"

#include <vector>

class VectorOrderBook : public IOrderBook{
    private:
        std::vector<Order> buy_orders;
        std::vector<Order> sell_orders;
    
    public:
        int getOrdersSize();
        void addOrder(Order order);
        void removeOrder(Order order);
        Order* getBestMatch(Order &order);
};

#endif