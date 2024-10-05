#include <iostream>
#include <string>
#include <vector>
#include "Tokenize.h"

using namespace std;

vector<string> Tokenize::tokenize(string csvLine, char separator) 
{
    // Stores the tokens
    vector<string> Tokenize::tokens;
    // Variables used to delineate the position of the tokens
    signed int start, end;
    start = csvLine.find_first_not_of(separator, 0);
    do 
    {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) 
        {
            // Nothing more to find
            break;
        }
        else if (end >= 0) 
        {
            // We found the separator
            // Start, Substring length
            token = csvLine.substr(start, end - start);
        }
        else 
        {
            // End is invalid
            token = csvLine.substr(start, csvLine.length() - start);
        }
        // Save the token
        tokens.push_back(token);
        // Move past this token
        start = end + 1;
    }
    while (end != string::npos);
    return tokens;
}