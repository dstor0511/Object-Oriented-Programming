#pragma once
#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
public:
    MerkelMain();

    void init();

    // Function to display the options offered to the use
    void printMenu();

    // Function to receive the input of the user for the main menu
    int getUserOption();

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

    // I learned that the keyword 'auto' allows compiler to deduce the type of var based on the expression used to initialize it.
    double computeAveragePrice(std::vector<OrderBookEntry> &orders);

    double computeLowPrice(std::vector<OrderBookEntry> &orders);

    double computeHighPrice(std::vector<OrderBookEntry> &orders);

    double computePriceSpread(std::vector<OrderBookEntry> &orders);
};
