#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "MerkelMain.h"

using namespace std;

OrderBookType stringToOrderBookType(const string& orderTypeStr) 
{
    if (orderTypeStr == "ask") 
    {
        return OrderBookType::ask;
    }
    else if (orderTypeStr == "bid") 
    {
        return OrderBookType::bid;
    }
    else 
    {
        throw invalid_argument("Invalid order type");
    }
}

string orderBookTypeToString(OrderBookType& type) 
{
    if (type == OrderBookType::ask) 
    {
        return "ask";
    }
    else if (type == OrderBookType::bid) 
    {
        return "bid";
    }
    else 
    {
        throw invalid_argument("Invalid type");
    }
}

vector<string> tokenize(string csvLine, char separator)
{
    vector<string> tokens;  // Corrected vector declaration
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

int main()
{
    string csvFilename{"20200317.csv"};
    ifstream csvFile{csvFilename};
    string line;

    if (!csvFile.is_open()) 
    {
        cout << "Problem opening file " << csvFilename << endl;
        return -1;
    }
    
    cout << "Opened " << csvFilename << endl;

    while (getline(csvFile, line))  // Corrected getline function
    {
        vector<string> tokens = tokenize(line, ',');

        if (tokens.size() != 5) continue;

        string timestamp = tokens.at(0);
        string product = tokens.at(1);
        OrderBookType orderType;
        double price, amount;

        try 
        {
            orderType = stringToOrderBookType(tokens.at(2));
        }
        catch (const exception& e)  
        {
            cout << "Improper data type" << endl;
            continue;  // Skip to the next iteration on invalid data
        }

        try 
        {
            price = stod(tokens.at(3));
        }
        catch (const exception& e) 
        {
            cout << "Improper price" << endl;
            continue;
        }

        try 
        {
            amount = stod(tokens.at(4));  // Removed redundant declaration
        }
        catch (const exception& e) 
        {
            cout << "Improper amount" << endl;
            continue;
        }

        // Output the values
        cout << "Timestamp: " << timestamp << endl;
        cout << "Product: " << product << endl;
        cout << "Order Type: " << orderBookTypeToString(orderType) << endl;
        cout << "Price: " << price << endl;
        cout << "Amount: " << amount << endl;
    }

    csvFile.close();
    return 0;
}
