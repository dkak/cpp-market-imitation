#include "../include/Graphics.h"
#include "../include/Order.h"
#include "../include/Market.h"

#include <iostream>

using namespace std;

void Graphics::showMenu(Market &market){
    
    while(true){
        int option;
        do{
            cout << endl << endl; 
            cout << " **************** New Day in the Market **************** ";
            cout << endl;
            cout << "Add order to market: " << endl;
            cout << "1. Add buyer" << endl;
            cout << "2. Add seller" << endl;
            cout << "3. Exit" << endl;
            cin >> option;
        }while(option<1 || option>3);

        if(option == 3 ){
            this->showMatchings(market.getMatchedOrders());
            this->showMarket(market.getBuyOrders(),market.getSellOrders());
            return;
        }
    
        long price;
        int quantity;
        cout << "Give the price : ";
        cin >> price;
        cout << "Give the quantity: ";
        cin >> quantity;

        int id=market.getBuyOrdersSize() + market.getSellOrdersSize();

        OrderType order_type;
        if(option == 1){
            order_type=OrderType::Buy;
        }else if(option == 2){
            order_type=OrderType::Sell;
        }

        Order new_order(id,price,quantity,order_type);
        market.addOrder(new_order);
        showMarket(market.getBuyOrders(),market.getSellOrders());
    }
}

void Graphics::showMarket(list<Order> buy_orders,list<Order> sell_orders){
    
    cout << endl << endl;
    cout << " ************* Buyers ************* ";
    cout << " | ";
    cout << " ************* Sellers ************* ";
    cout << endl;

    if(buy_orders.size()<sell_orders.size()){
        auto it_buy = buy_orders.begin();
        auto it_sell = sell_orders.begin();

        for(int i=0; i<buy_orders.size(); i++){
            std::advance(it_buy, i);
            std::advance(it_sell, i);
            Order buy_order=*it_buy;
            Order sell_order=*it_sell;
            cout << "ID : " << buy_order.getId() << " -- ";
            cout << "Price: " << buy_order.getPrice() << " -- ";
            cout << "Quantity: " << buy_order.getQuantity();
            cout << "            |";
            cout << "ID : " << sell_order.getId() << " -- ";
            cout << "Price: " << sell_order.getPrice() << " -- ";
            cout << "Quantity: " << sell_order.getQuantity();
            cout << endl;
        }

        for(int i=buy_orders.size(); i<sell_orders.size(); i++){
            std::advance(it_sell, i);
            Order sell_order=*it_sell;
            cout << "                         ";
            cout << "                                     | ";
            cout << "ID : " << sell_order.getId() << " -- ";
            cout << "Price: " << sell_order.getPrice() << " -- ";
            cout << "Quantity: " << sell_order.getQuantity();
            cout << endl;
        }
    }
    else if(buy_orders.size()>sell_orders.size()){
        auto it_buy = buy_orders.begin();
        auto it_sell = sell_orders.begin();

        for(int i=0; i<sell_orders.size(); i++){
            std::advance(it_buy, i);
            std::advance(it_sell, i);
            Order buy_order=*it_buy;
            Order sell_order=*it_sell;
            cout << "ID : " << buy_order.getId() << " -- ";
            cout << "Price: " << buy_order.getPrice() << " -- ";
            cout << "Quantity: " << buy_order.getQuantity();
            cout << "         |";
            cout << "ID : " << sell_order.getId() << " -- ";
            cout << "Price: " << sell_order.getPrice() << " -- ";
            cout << "Quantity: " << sell_order.getQuantity();
            cout << endl;
        }

        for(int i=sell_orders.size(); i<buy_orders.size(); i++){
            std::advance(it_buy, i);
            Order buy_order=*it_buy;
            cout << "ID : " << buy_order.getId() << " -- ";
            cout << "Price: " << buy_order.getPrice() << " -- ";
            cout << "Quantity: " << buy_order.getQuantity();
            cout << " | ";
            cout << endl;
        }
    }
    else{
        auto it_buy = buy_orders.begin();
        auto it_sell = sell_orders.begin();

        for(int i=0; i<buy_orders.size(); i++){
            std::advance(it_buy, i);
            std::advance(it_sell, i);
            Order buy_order=*it_buy;
            Order sell_order=*it_sell;
            cout << "ID : " << buy_order.getId() << " -- ";
            cout << "Price: " << buy_order.getPrice() << " -- ";
            cout << "Quantity: " << buy_order.getQuantity();
            cout << "         |";
            cout << "ID : " << sell_order.getId() << " -- ";
            cout << "Price: " << sell_order.getPrice() << " -- ";
            cout << "Quantity: " << sell_order.getQuantity();
            cout << endl;
        }
    }
}

void Graphics::showMatchings(list<OrderMatch> matched_orders){
    
    for(OrderMatch matched_order:matched_orders){
        cout << "********** Order Matches **********" << endl;
        cout << "Buyer ID: " << matched_order.getBuyOrder().getId();
        cout << " -- ";
        cout << "Price: " << matched_order.getBuyOrder().getPrice();
        cout << " -- ";
        cout << "Quantity: " << matched_order.getBuyOrder().getQuantity();
        cout << " *** Seller *** " << endl;
        cout << "Seller ID: " << matched_order.getSellOrder().getId();
        cout << " -- ";
        cout << "Price: " << matched_order.getSellOrder().getPrice();
        cout << " -- ";
        cout << "Quantity: " << matched_order.getSellOrder().getQuantity();
        cout << endl;
    }
}