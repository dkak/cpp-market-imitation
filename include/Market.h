#ifndef MARKET_H
#define MARKET_H

#include "IOrderBook.h"
#include "Order.h"
#include "OrderMatch.h"

#include <list>
#include <memory>

class Market{

    private:
        std::unique_ptr<IOrderBook> order_book;
        std::list<OrderMatch> matched_orders;

    public:
        Market(std::unique_ptr<IOrderBook> order_book);
        void processIncomingOrder(const Order order);
        void addMatchedOrder(OrderMatch matched_order);
};

#endif