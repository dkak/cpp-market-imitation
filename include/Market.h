#ifndef MARKET_H
#define MARKET_H

#include "Order.h"
#include "OrderMatch.h"

#include <list>
class Market{

    private:
        std::list<Order> buy_orders;
        std::list<Order> sell_orders;
        std::list<OrderMatch> matched_orders;
    public:
        std::list<Order> getBuyOrders();
        std::list<Order> getSellOrders();
        std::list<OrderMatch> getMatchedOrders();
        int getBuyOrdersSize();
        int getSellOrdersSize();

        void addOrder(Order &order);
        void removeOrder(Order buy_order);
        bool findOrder(Order &order,std::list<Order> &pair_orders);
        void addMatchedOrder(OrderMatch matched_order);
};

#endif