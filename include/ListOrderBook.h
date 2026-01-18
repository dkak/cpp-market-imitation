#ifndef LISTORDERBOOK_H
#define LISTORDERBOOK_H

#include "IOrderBook.h"

#include <list>

class ListOrderBook : public IOrderBook{
    private:
        std::list<Order> buy_orders;
        std::list<Order> sell_orders;

    public:
        void addOrder(Order order);
        void removeOrder(Order order);
        Order getMatchedOrder(Order order);
};

#endif