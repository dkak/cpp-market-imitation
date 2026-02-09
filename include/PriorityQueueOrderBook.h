#ifndef PRIORITYQUEUEORDERBOOK_H
#define PRIORITYQUEUEORDERBOOK_H

#include "IOrderBook.h"

#include <queue>
#include <vector>

struct CompareBuy {
    bool operator()(Order a,Order b) const {
        // Max-Heap: Higher price has higher priority
        return a.getPrice() < b.getPrice();
    }
};

struct CompareSell {
    bool operator()(Order a,Order b) const {
        // Min-Heap: Lower price has higher priority
        return a.getPrice() > b.getPrice();
    }
};

class PriorityQueueOrderBook : public IOrderBook{
    private:
        std::priority_queue<Order,std::vector<Order>,CompareBuy> buy_orders;
        std::priority_queue<Order,std::vector<Order>,CompareSell> sell_orders;
    
    public:
        int getOrdersSize();
        void addOrder(Order order);
        void removeOrder(Order order);
        Order* getBestMatch(Order &order);
};

#endif