#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include <iostream>
#include <vector>
#include <limits>

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    bool status = true;
    while (status)
    {
        printMenu();
        input = getUserOption();
        status = processUserOption(input);
    }
}

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

    std::cout << "Current Time is: " << currentTime << std::endl;
}

// Function to receive the input of the user for the main menu
int MerkelMain::getUserOption()
{

    std::cout << "Type in 1-7" << std::endl;

    // Request the user for an input
    int userOption;
    std::cin >> userOption;

    // Print user input
    std::cout << "You chose: " << userOption << std::endl;

    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help. Your aim is to make money, analyze the market, make bids, and offers" << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::printStats()
{
    for (std::string const p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << orderBook.getHighPrice(entries) << std::endl;
        std::cout << "Average ask: " << orderBook.getAvgPrice(entries) << std::endl;
        std::cout << "Price Spread of " << orderBook.getPriceSpread(entries) << std::endl;
        std::cout << "Min ask: " << orderBook.getLowPrice(entries) << std::endl;
        std::cout << " " << std::endl;
    }
}

void MerkelMain::makeAsk()
{
    std::cout << "Mark and ask - Enter the amount: product,price,amount" << std::endl;
    std::cout << "eg:" << std::endl;
    std::cout << "ETCH/BTC,200,0,5" << std::endl;

    std::string input;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, input);
    std::cout << "You typed: " << input << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::makeBid()
{
    std::cout << "Make a bid - Enter the amount" << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your Wallet is Empty" << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::nextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
    std::cout << " " << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}

bool MerkelMain::exit()
{
    std::cout << "Good Bye!" << std::endl;
    std::cout << " " << std::endl;

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
        makeAsk();
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