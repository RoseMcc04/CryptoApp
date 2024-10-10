#pragma once

#include <string>
#include <vector>
#include "CSVReader.h"
#include "OrderBookEntry.h"

class OrderBook 
{
    public:
        /**
         * Constructor, reading a csv data file
         */
        OrderBook(std::string filename);
        /**
         * Returns a vector of all known products in the dataset
         */
        std::vector<std::string> getKnownProducts();
        /**
         * Return a vector of Orders according to the parameters
         */
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                            std::string product,
                                            std::string timestamp);
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);
    
    private:
        vector<OrderBookEntry> orders;
};