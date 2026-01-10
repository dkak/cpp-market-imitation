#ifndef MARKET_H
#define MARKET_H


#include "Order.h"

#include <list>

class Market{

    private:
        std::list<Order> buy_orders;
        std::list<Order> sell_orders;
        std::list<Order> removed_buy_orders;
        std::list<Order> removed_sell_orders;
    
    public:
        std::list<Order> getBuyOrders();
        std::list<Order> getSellOrders();
        void addOrder(Order &order);
        void removeBuyOrder(Order buy_order);
        void removeSellOrder(Order sell_order);
        bool findBuyOrder(Order &sell_order);
        bool findSellOrder(Order &buy_order);
        int getBuyOrdersSize();
        int getSellOrdersSize();
        
};

#endif