#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "CSVReader.h"
#include "MerkelMain.h"

void MerkelMain::printMenu() 
{
    cout << "1: Print help " << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Make an offer" << endl;
    cout << "4: Make a bid" << endl;
    cout << "5: Print Wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "=============" << endl;
}

void MerkelMain::printHelp() 
{
    cout << "Help - your aim is to make money. " << 
        "Analyze the market and make bids and offers." << endl;
}

void MerkelMain::printMarketStats() 
{
    for (string const& p : orderBook.getKnownProducts()) 
    {
        cout << "Product: " << p << endl;
        vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p,
            "2020/03/17 17:01:24.884492"); 
        cout << "Asks seen: " << entries.size() << endl;
        cout << "Max ask: " << OrderBook::getHighPrice(entries) << endl;
        cout << "Min ask: " << OrderBook::getLowPrice(entries) << endl;
    }
    // cout << "Market looks good. " << endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& e : orders) 
    // {
    //     if (e.orderType == OrderBookType::ask) 
    //     {
    //         asks++;
    //     }
    //     if (e.orderType == OrderBookType::bid) 
    //     {
    //         bids++;
    //     }
    // }
    // cout << "OrderBook asks: " << asks << " bids: " << bids << endl;
}

void MerkelMain::enterOffer() 
{
    cout << "Mark an offer - enter the amount: " << endl;
}

void MerkelMain::enterBid() 
{
    cout << "Make a bid - enter the amount: " << endl;
}

void MerkelMain::printWallet() 
{
    cout << "Your wallet is empty. " << endl;
}

void MerkelMain::gotoNextTimeframe() 
{
    cout << "Going to next time frame. " << endl;
}

int MerkelMain::getUserOption() 
{
    int userOption;

    cout << "Type in 1-6" << endl;
    cin >> userOption;
    cout << "You chose: " << userOption << endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption) 
{
    switch (userOption) 
    {
        case 1:
            printHelp();
            break;
        case 2:
            printMarketStats();
            break;
        case 3:
            enterOffer();
            break;
        case 4:
            enterBid();
            break;
        case 5:
            printWallet();
            break;
        case 6:
            gotoNextTimeframe();
            break;
        default:
            cout << "Invalid choice. Choose 1-6" << endl;
            break;
    }
}

void MerkelMain::init()
{
    // loadOrderBook();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}