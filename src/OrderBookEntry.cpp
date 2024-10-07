#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry() 
{
    price = 0;
    amount = 0;
    timestamp = "";
    product = "";
    orderType = OrderBookType::unknown;
}

OrderBookEntry::OrderBookEntry(double price, double amount, string timestamp, 
    string product, OrderBookType orderType) 
{
    this->price = price;
    this->amount = amount;
    this->timestamp = timestamp;
    this->product = product;
    this->orderType = orderType;
}

OrderBookType OrderBookEntry::stringToOrderBookType(string s) 
{
    if (s == "ask") 
    {
        return OrderBookType::ask;
    }
    else if (s == "bid") 
    {
        return OrderBookType::bid;
    }
    else 
    {
        return OrderBookType::unknown;
    }
}
