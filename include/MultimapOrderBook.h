#ifndef MULTIMAPORDERBOOK_H
#define MULTIMAPORDERBOOK_H

#include "IOrderBook.h"

#include <map>

class MultimapOrderBook : public IOrderBook{
    private:
        std::multimap<double,Order,std::greater<double>> buy_orders;
        std::multimap<double,Order> sell_orders;
    
    public:
        int getOrdersSize();
        void addOrder(Order order);
        void removeOrder(Order order);
        Order* getBestMatch(Order &order);
};

#endif