#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Market.h"
#include "Order.h"

#include <iostream>

using namespace std;

class Graphics{

    public:
        void showMenu(Market &market);
        void showMarket(list<Order> buy_orders,list<Order> sell_orders);
        void showMatchings(
            list<Order> removed_buy_orders,
            list<Order> removed_sell_orders
        );
};

#endif