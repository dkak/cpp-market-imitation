#ifndef MARKET_H
#define MARKET_H

#include "Order.h"
#include "OrderMatch.h"

#include <list>
#include <map>

class Market{

    private:
        std::list<Order> buy_orders;
        std::list<Order> sell_orders;
        std::list<OrderMatch> matched_orders;
    public:
        std::list<Order> getBuyOrders();
        std::list<Order> getSellOrders();
        std::list<OrderMatch> Market::getMatchedOrders();
        int getBuyOrdersSize();
        int getSellOrdersSize();

        void addOrder(Order &order);
        void addMatchedOrder(OrderMatch matched_order);
        void removeBuyOrder(Order buy_order);
        void removeSellOrder(Order sell_order);
        bool findBuyOrder(Order &sell_order);
        bool findSellOrder(Order &buy_order);
};

#endif