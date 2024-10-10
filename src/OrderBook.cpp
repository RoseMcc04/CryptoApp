#include <iostream>
#include <map>
#include "CSVReader.h"
#include "OrderBook.h"

using namespace std;

OrderBook::OrderBook(string filename) 
{
    orders = CSVReader::readCSV(filename);
}

vector<string> OrderBook::getKnownProducts() 
{
    vector<string> products;
    map<string, bool> prodMap; 
    for (OrderBookEntry& e : orders) 
    {
        prodMap[e.product] = true;
    }
    for (auto const& e : prodMap) 
    {
        products.push_back(e.first);
    }
    return products;
}

vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, string product, string timestamp) 
{
    vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry& e : orders) 
    {
        if (e.orderType == type && 
            e.product == product && 
            e.timestamp == timestamp) 
        {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}

double OrderBook::getHighPrice(vector<OrderBookEntry>& orders) 
{
    double max = orders.at(0).price;
    for (OrderBookEntry& e : orders) 
    {
        if (e.price > max) 
        {
            max = e.price;
        }
    }
    return max;
}

double OrderBook::getLowPrice(vector<OrderBookEntry>& orders) 
{
    double min = orders.at(0).price;
    for (OrderBookEntry& e : orders) 
    {
        if (e.price < min) 
        {
            min = e.price;
        }
    }
    return min;
}
