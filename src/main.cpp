#include <iostream>
#include <string>
#include <vector>
#include "MerkelMain.h"

using namespace std;

int main()
{
    // MerkelMain app{};
    // app.init();

    Tokenize tokenizer;
    string s = "hello,I have,3 tokens";
    vector<string> result = tokenizer.tokenize(s, ',');
    for (const auto& token : result) 
    {
        cout << token << endl;
    }
    return 0;
}
