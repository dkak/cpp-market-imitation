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
        int getId();
        double getPrice();
        void setPrice(long price);
        int getQuantity();
        void setQuantity(int quantity);
        OrderType getSide();

        bool operator==(const Order& order) const {
            return this->id == order.id;
        }
};

#endif