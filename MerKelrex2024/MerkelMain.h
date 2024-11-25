#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
public:
    MerkelMain();

    /** Call this to start the simulation*/
    void init();

private:
    // Function to display the options offered to the use
    void printMenu();

    // Function to receive the input of the user for the main menu
    int getUserOption();
    void loadOrderBook();
    void printHelp();
    void printStats();

    void makeOffer();
    void makeBid();
    void printWallet();
    void nextTimeFrame();
    bool exit();

    // Function to process the option of the user and returns True, for the app to continue running
    // or False to close the app, when 7 is selected.
    bool processUserOption(int userOption);

    OrderBook orderBook{"dataFile.csv"};

    // Stats functions
    // double computeAveragePrice(std::vector<OrderBookEntry> &orders);
    // double computeLowPrice(std::vector<OrderBookEntry> &orders);
    // double computeHighPrice(std::vector<OrderBookEntry> &orders);
    // double computePriceSpread(std::vector<OrderBookEntry> &orders);
};
