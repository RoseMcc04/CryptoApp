#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

enum class OrderBookType
{
    ask,
    bid, 
    unknown
};

class OrderBookEntry 
{
    public:
        OrderBookEntry();
        OrderBookEntry(double price, double amount, string timestamp, 
            string product, OrderBookType orderType);
        static OrderBookType stringToOrderBookType(string s);
        double price;
        double amount;
        string timestamp;
        string product;
        OrderBookType orderType;
};