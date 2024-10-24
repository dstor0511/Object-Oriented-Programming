#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include <iostream>
#include <vector>

// Function to display the options offered to the use
void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help" << std::endl;

    // 2 print exchange stats
    std::cout << "2: Print Exchange Stats" << std::endl;

    // 3 make an offer
    std::cout << "3: Make an Offer" << std::endl;

    // 4 make a bid
    std::cout << "4: Make a Bid" << std::endl;

    // 5 print wallet
    std::cout << "5: Print Wallet" << std::endl;

    // 6 Continue
    std::cout << "6: Continue" << std::endl;

    // 7 Exit the app
    std::cout << "7: Exit" << std::endl;

    std::cout << "--------------------" << std::endl;
}

// Function to receive the input of the user for the main menu
int MerkelMain::getUserOption()
{

    std::cout << "Type in 1-7" << std::endl;

    // Request the user for an input
    int userOption;
    std::cin >> userOption;

    // Print user input
    std::cout << "You chose " << userOption << std::endl;

    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help. Your aim is to make money, analyze the market, make bids, and offers" << std::endl;
}

void MerkelMain::printStats()
{
    std::cout << "Market Looks Good" << std::endl;
}

void MerkelMain::makeOffer()
{
    std::cout << "Mark and offer - Enter the amount" << std::endl;
}

void MerkelMain::makeBid()
{
    std::cout << "Make a bid - Enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your Wallet is Empty" << std::endl;
}

void MerkelMain::nextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
}

bool MerkelMain::exit()
{
    std::cout << "Good Bye!" << std::endl;
    // Close App
    return false;
}

// Function to process the option of the user and returns True, for the app to continue running
// or False to close the app, when 7 is selected.
bool MerkelMain::processUserOption(int userOption)
{
    // Check user input. Bad Input
    if (userOption == 0)
    {
        std::cout << "Invalid Input. Choose 1-7" << std::endl;
        return true;
    }

    // Check user input. Option 1
    if (userOption == 1)
    {
        MerkelMain::printHelp();
    }

    // Check user input. Option 2
    if (userOption == 2)
    {
        MerkelMain::printStats();
    }

    // Check user input. Option 3
    if (userOption == 3)
    {
        MerkelMain::makeOffer();
    }

    // Check user input. Option 4
    if (userOption == 4)
    {
        MerkelMain::makeBid();
    }

    // Check user input. Option 5
    if (userOption == 5)
    {
        MerkelMain::printWallet();
    }

    // Check user input. Option 6
    if (userOption == 6)
    {
        MerkelMain::nextTimeFrame();
    }

    // Check user input. Option 7
    if (userOption == 7)
    {
        return exit();
    }

    // Continue for valid menu options
    return true;
}

// I learned that the keyword 'auto' allows compiler to deduce the type of var based on the expression used to initialize it.
double MerkelMain::computeAveragePrice(std::vector<OrderBookEntry> &orders)
{
    double totalPrice = 0;
    for (const auto &order : orders)
    {
        totalPrice += order.price;
    }
    return totalPrice / orders.size();
}

double MerkelMain::computeLowPrice(std::vector<OrderBookEntry> &orders)
{
    double lowPrice = orders[0].price; // Start with the first order
    for (const auto &order : orders)
    {
        if (order.price < lowPrice)
        {
            lowPrice = order.price;
        }
    }
    return lowPrice;
}

double MerkelMain::computeHighPrice(std::vector<OrderBookEntry> &orders)
{
    double highPrice = orders[0].price; // Start with the first order
    for (const auto &order : orders)
    {
        if (order.price > highPrice)
        {
            highPrice = order.price;
        }
    }
    return highPrice;
}

double MerkelMain::computePriceSpread(std::vector<OrderBookEntry> &orders)
{
    double lowPrice = MerkelMain::computeLowPrice(orders);
    double highPrice = MerkelMain::computeHighPrice(orders);
    return highPrice - lowPrice;
}