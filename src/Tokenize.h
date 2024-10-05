#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tokenize 
{
    private: 
        vector<string> tokenize(string csvLine, char separator);
        vector<string> tokens;
}