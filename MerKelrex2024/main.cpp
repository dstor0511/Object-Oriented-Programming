// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"

// Function to display the options offered to the use
void printMenu()
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
int getUserOption()
{

    std::cout << "Type in 1-7" << std::endl;

    // Request the user for an input
    int userOption;
    std::cin >> userOption;

    // Print user input
    std::cout << "You chose " << userOption << std::endl;

    return userOption;
}

void printHelp()
{
    std::cout << "Help. Your aim is to make money, analyze the market, make bids, and offers" << std::endl;
}

void printStats()
{
    std::cout << "Market Looks Good" << std::endl;
}

void makeOffer()
{
    std::cout << "Mark and offer - Enter the amount" << std::endl;
}

void makeBid()
{
    std::cout << "Make a bid - Enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your Wallet is Empty" << std::endl;
}

void nextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
}

bool exit()
{
    std::cout << "Good Bye!" << std::endl;
    // Close App
    return false;
}

// Function to process the option of the user and returns True, for the app to continue running
// or False to close the app, when 7 is selected.
bool processUserOption(int userOption)
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
        printHelp();
    }

    // Check user input. Option 2
    if (userOption == 2)
    {
        printStats();
    }

    // Check user input. Option 3
    if (userOption == 3)
    {
        makeOffer();
    }

    // Check user input. Option 4
    if (userOption == 4)
    {
        makeBid();
    }

    // Check user input. Option 5
    if (userOption == 5)
    {
        printWallet();
    }

    // Check user input. Option 6
    if (userOption == 6)
    {
        nextTimeFrame();
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
double computeAveragePrice(std::vector<OrderBookEntry> &orders)
{
    double totalPrice = 0;
    for (const auto &order : orders)
    {
        totalPrice += order.price;
    }
    return totalPrice / orders.size();
}

double computeLowPrice(std::vector<OrderBookEntry> &orders)
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

double computeHighPrice(std::vector<OrderBookEntry> &orders)
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

double computePriceSpread(std::vector<OrderBookEntry> &orders)
{
    double lowPrice = computeLowPrice(orders);
    double highPrice = computeHighPrice(orders);
    return highPrice - lowPrice;
}

int main()
{
    // std::vector<double> prices;
    // std::vector<double> amounts;
    // std::vector<std::string> timeStamps;
    // std::vector<std::string> product;
    // std::vector<OrderBookType> orderTypes;

    //// Status of the app
    // bool status = true;
    //
    // while (status){

    //	// Print Menu Funct.
    //	printMenu();

    //	// Request and receive user option
    //	int userOption = getUserOption();

    //	// Run the app and process the user option
    //	status = processUserOption(userOption);
    //}

    std::vector<OrderBookEntry> orders;

    orders.push_back(OrderBookEntry{10000, 0.52, "2024/17/05 17:52:24.884492", "BTC/USDT", OrderBookType::bid});
    orders.push_back(OrderBookEntry{300, 0.99, "2024/10/06 19:32:24.872592", "BTC/ETH", OrderBookType::bid});
    orders.push_back(OrderBookEntry{2200, 0.31, "2024/17/10 22:11:24.358492", "ETH/BTC", OrderBookType::ask});
    // chat GPT generated inputs for ease
    orders.push_back(OrderBookEntry{10000, 0.52, "2024/17/05 17:52:24.884492", "BTC/USDT", OrderBookType::bid});
    orders.push_back(OrderBookEntry{10020, 0.75, "2024/17/05 17:53:45.112233", "BTC/USDT", OrderBookType::ask});
    orders.push_back(OrderBookEntry{9995, 0.40, "2024/17/05 17:54:11.987654", "BTC/USDT", OrderBookType::bid});
    orders.push_back(OrderBookEntry{10010, 1.00, "2024/17/05 17:55:23.456789", "BTC/USDT", OrderBookType::ask});
    orders.push_back(OrderBookEntry{10050, 0.32, "2024/17/05 17:56:07.123456", "BTC/USDT", OrderBookType::ask});
    orders.push_back(OrderBookEntry{9980, 0.85, "2024/17/05 17:57:30.654321", "BTC/USDT", OrderBookType::bid});

    for (OrderBookEntry &order : orders)
    {
        std::cout << "The price is: " << order.price << std::endl;
    }

    // Call functions to compute the statistics
    std::cout << "Average Price: " << computeAveragePrice(orders) << std::endl;
    std::cout << "Low Price: " << computeLowPrice(orders) << std::endl;
    std::cout << "High Price: " << computeHighPrice(orders) << std::endl;
    std::cout << "Price Spread: " << computePriceSpread(orders) << std::endl;

    return 0;
}