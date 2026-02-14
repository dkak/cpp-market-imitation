# 📊 OrderBook Benchmark Tool

A C++ performance benchmarking suite designed to compare different data structure implementations for a financial market Order Book. This project evaluates how **std::vector**, **std::list**, and **std::multimap** perform under high-frequency order processing scenarios.



## 🎮 Overview
The application simulates a market environment by generating a large volume of "Buy" and "Sell" orders. It measures the total execution time (latency) for:
* **Insertion:** Adding new orders to the book.
* **Matching:** Finding and removing matching orders.
* **Storage:** Managing the remaining liquidity in the book.

---

## 🛠 Project Structure
* **Market:** The engine that orchestrates order flow and manages the book life cycle.
* **IOrderBook:** The abstract interface defining standard order book behavior.
* **VectorOrderBook:** Implementation using **std::vector**.
* **ListOrderBook:** Implementation using **std::list**.
* **MultimapOrderBook:** Implementation using **std::multimap**.

---

## 🚀 Quick Start

### Prerequisites
Ensure you have a C++ compiler (like `g++`) installed on your machine.

### Compilation
To get the most accurate benchmark results, ensure you compile with optimization flags (**-O3**). Run the following command in your terminal:

```bash
g++ main.cpp src/*.cpp -Iinclude -o orderbook_benchmark -O3
