#ifndef Order_H
#define Order_H

enum class OrderType {Buy,Sell};

class Order{
    private:
        int id;
        long price;
        int quantity;
        OrderType side;
    public:
        Order(int id,double price,int quantity,OrderType side);
        Order()=default;
        
        int getId();
        double getPrice();
        int getQuantity();
        void setQuantity(int quantity);
        void reduceQuantity(int quantity);
        OrderType getSide();

        bool operator==(const Order& order) const {
            return this->id == order.id;
        }
};

#endif