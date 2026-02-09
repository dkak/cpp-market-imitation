#ifndef MARKET_H
#define MARKET_H

#include "IOrderBook.h"
#include "Order.h"
#include "OrderMatch.h"

#include <unordered_map>
#include <memory>

class Market{

    private:
        std::unique_ptr<IOrderBook> order_book;
        std::unordered_map<int,OrderMatch> matched_orders;

    public:
        Market(std::unique_ptr<IOrderBook> order_book);
        
        int getOrdersSize();
        std::unique_ptr<IOrderBook> getOrderBook();
        void processIncomingOrder(Order &order);
        void addMatchedOrder(OrderMatch matched_order);
        void completeTransaction(Order &incoming_order,Order &resting_order);
        std::unordered_map<int,OrderMatch> getMatchedOrders();
};

#endif