#include "include/Graphics.h"
#include "include/Market.h"
#include "include/IOrderBook.h"
#include "include/ListOrderBook.h"

#include <iostream>

int main(){

    // 1. Setup the Market with a ListOrderBook
    auto book = std::make_unique<ListOrderBook>();
    Market market(std::move(book));

    std::cout << "--- Starting Order Book Test ---\n";

    // 2. Create some resting Sell orders (the "Book")
    // We want to see if a Buyer can match these
    Order sell1(101, 100.0, 50, OrderType::Sell);
    Order sell2(102, 105.0, 40, OrderType::Sell);
    
    market.processIncomingOrder(sell1);
    market.processIncomingOrder(sell2);
    
    std::cout << "Initial Book Size (Sells): " << market.getOrdersSize() << std::endl;

    // 3. Create an incoming Buy order that should match
    // Price 102.0 means it should fully clear sell1 (at 100) 
    // and partially clear sell2 (at 105 is too high, so it should stop)
    // Actually, let's set price to 105.0 to match both.
    Order buy1(201, 105.0, 60, OrderType::Buy);
    
    std::cout << "\nProcessing Buy Order: ID 201, Price 105.0, Qty 60..." << std::endl;
    market.processIncomingOrder(buy1);

    // 4. Verify Results
    std::cout << "\n--- Results ---" << std::endl;
    std::cout << "Remaining Orders in Book: " << market.getOrdersSize() << std::endl;
    
    // Check matched orders
    auto matches = market.getMatchedOrders();
    std::cout << "Number of Match Events: " << matches.size() << std::endl;

    for (auto [id, match] : matches) {
        std::cout << "Match ID: " << id 
                  << " | Traded Qty: " << match.getTradedQuantity() 
                  << " | Price: " << match.getRestingOrder().getPrice() << std::endl;
    }

    return 0;
}