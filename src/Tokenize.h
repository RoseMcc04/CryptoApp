#pragma once

#include <string>
#include <vector>

class Tokenize 
{
    public:
        Tokenize() = default;
        std::vector<std::string> tokenize(std::string csvLine, char separator);

    private: 
        std::vector<std::string> tokens;
};