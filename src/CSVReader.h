#pragma once

#include <string>
#include <vector>
#include "OrderBookEntry.h"

using namespace std;

class CSVReader 
{
    public:
        CSVReader();
        static vector<OrderBookEntry> readCSV(string csvFile);
    
    private:
        static vector<string> tokenize(string csvLine, char separator)
        static OrderBookEntry stringsToOBE(vector<string> strings);
};