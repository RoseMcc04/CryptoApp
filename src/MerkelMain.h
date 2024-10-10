#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "OrderBook.h"
#include "OrderBookEntry.h"

class MerkelMain
{
public:
    MerkelMain() = default;
    /** Call this to start the sim */
    void init();

private:
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void processUserOption(int userOption);

    OrderBook orderBook{"20200317.csv"};
};