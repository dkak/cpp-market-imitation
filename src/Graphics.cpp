#include "../include/Graphics.h"
#include "../include/Order.h"
#include "../include/Market.h"

#include <iostream>

using namespace std;

void Graphics::showMenu(Market &market){
    
    while(true){
        int option;
        do{
            cout << endl << endl << " **************** New Day in the Market **************** " << endl;
            cout << "Add order to market: " << endl;
            cout << "1. Add buyer" << endl;
            cout << "2. Add seller" << endl;
            cout << "3. Exit" << endl;
            cin >> option;
        }while(option<1 || option>3);

        if(option == 3 ) return;
    
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
    
    cout << endl << endl << " ******************** Buyers ARE : ******************** " << endl;
    for(Order buy_order:buy_orders){
        cout << "ID : " << buy_order.getId() << " -- " << "Price : " << buy_order.getPrice() << " -- " << "Quantity : " << buy_order.getQuantity() << endl;
    }

    cout << endl << " ******************** Sellers ARE : ******************** " << endl;
    for(Order sell_order: sell_orders){
        cout << "ID : " << sell_order.getId() << " -- " << "Price : " << sell_order.getPrice() << " -- " << "Quantity : " << sell_order.getQuantity() << endl;
    }
}