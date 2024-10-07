#include <iostream>
#include <string>
#include <vector>
#include "CSVReader.h"

using namespace std;

CSVReader::CSVReader() 
{

}

vector<OrderBookEntry> CSVReader::readCSV(string csvFile) 
{
    vector<OrderBookEntry> entries;
    return entries;
}

vector<string> CSVReader::tokenize(string line, char separator) 
{
    vector<string> tokens;
    return tokens;
}

OrderBookEntry stringToOBE(vector<string> strings)  
{
    OrderBookEntry obe{};
    return obe;
}
