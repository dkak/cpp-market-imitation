#include "include/Graphics.h"
#include "include/Market.h"
#include "include/IOrderBook.h"
#include "include/ListOrderBook.h"
#include "include/VectorOrderBook.h"
#include "include/MultimapOrderBook.h"
// #include "include/PriorityQueueOrderBook.h"

#include <iostream>
#include <iostream>
#include <vector>
#include <chrono>
#include <memory>

// Helper to generate a bunch of dummy orders
std::vector<Order> generateOrders(int count) {
    std::vector<Order> orders;
    for (int i = 0; i < count; ++i) {
        // Alternates Buy/Sell, randomish prices around 100.0
        OrderType side = (i % 2 == 0) ? OrderType::Buy : OrderType::Sell;
        double price = (side == OrderType::Buy) ? (95.0 + (i % 10)) : (105.0 - (i % 10));
        orders.emplace_back(i, price, 10, side);
    }
    return orders;
}

void runBenchmark(std::string name, std::unique_ptr<IOrderBook> book, const std::vector<Order>& testData) {
    Market market(std::move(book));
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (auto order : testData) {
        market.processIncomingOrder(order);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "[" << name << "] Processed " << testData.size() 
              << " orders in " << duration.count() << " us. "
              << "Remaining in book: " << market.getOrdersSize() << std::endl;
}

int main() {
    const int ORDER_COUNT = 1000;
    auto testData = generateOrders(ORDER_COUNT);

    std::cout << "--- Starting OrderBook Benchmarks (" << ORDER_COUNT << " orders) ---" << std::endl;

    runBenchmark("Vector Implementation", std::make_unique<VectorOrderBook>(), testData);
    runBenchmark("List Implementation", std::make_unique<ListOrderBook>(), testData);
    runBenchmark("Multimap Implementation", std::make_unique<MultimapOrderBook>(), testData);
    // runBenchmark("Priority Queue Implementation", std::make_unique<PriorityQueueOrderBook>, testData);

    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get(); // Waits for a key press
    return 0;
}