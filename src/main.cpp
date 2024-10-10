#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"

using namespace std;

int main()
{
    MerkelMain app{};
    app.init();
    return 0;
}
