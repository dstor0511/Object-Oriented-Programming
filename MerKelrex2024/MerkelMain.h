#pragma once
#include <vector>
#include "OrderBook.h"
#include "OrderBookEntry.h"

// MerkelMain class definition
class MerkelMain
{
public:
    // Constructor for MerkelMain
    MerkelMain();

    /** Call this to start the simulation */
    void init();

private:
    // Function to display the options offered to the user
    void printMenu();

    // Function to receive the input of the user for the main menu
    int getUserOption();

    // Function to load the order book
    void loadOrderBook();

    // Function to print help information
    void printHelp();

    // Function to print statistics
    void printStats();

    // Function to make an ask order
    void makeAsk();

    // Function to make a bid order
    void makeBid();

    // Function to print the wallet
    void printWallet();

    // Function to move to the next time frame
    void nextTimeFrame();

    // Function to exit the application
    bool exit();

    // Function to process the option of the user and returns True for the app to
    // continue running or False to close the app when 7 is selected.
    bool processUserOption(int userOption);

    // Current time in the simulation
    std::string currentTime;

    // OrderBook object to manage orders
    OrderBook orderBook{"dataFile.csv"};
};
