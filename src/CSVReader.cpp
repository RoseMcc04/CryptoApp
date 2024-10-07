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

OrderBookEntry CSVReader::stringsToOBE(vector<string> tokens)
{
    double price, amount;
    if (tokens.size() != 5) 
    {
        cout << "Bad line!" << endl;
        throw exception{};
    }
    try 
    {
        price = stod(tokens.at(3));
        amount = stod(tokens.at(4));
        cout << price << ":" << amount << endl;
    }
    catch (const exception& e) 
    {
        cout << "Bad float! " << tokens.at(3) << endl;
        cout << "Bad float! " << tokens.at(4) << endl;
    }
    OrderBookEntry obe
    {
        price, 
        amount, 
        tokens.at(0), 
        tokens.at(1),
        OrderBookEntry::stringToOrderBookType(tokens.at(2))
    };
    return obe;
}

vector<string> CSVReader::tokenize(string csvLine, char separator) 
{
    vector<string> tokens;
    signed int start, end;
    string token;
    start = csvLine.find_first_not_of(separator, 0);
    do
    {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end + 1;
    }
    while (end != string::npos);
    
    return tokens;
}
