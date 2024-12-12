#include "MerkelMain.h"
#include <iostream>
#include <limits>
#include <vector>
#include "OrderBookEntry.h"

// Constructor for MerkelMain
MerkelMain::MerkelMain() {}

// Function to initialize the application
void MerkelMain::init()
{
    int input;
    // Set the current time to the earliest time in the order book
    currentTime = orderBook.getEarliestTime();
    bool status = true;
    while (status)
    {
        // Display the menu options
        printMenu();
        // Get the user's option
        input = getUserOption();
        // Process the user's input and update the status accordingly
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

    // 3 make an ask
    std::cout << "3: Make an Ask" << std::endl;

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
    // Request the user for an input
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-7" << std::endl;
    std::getline(std::cin, line); // Read the user's input as a string

    try
    {
        userOption = std::stoi(line); // Convert the input string to an integer
    }
    catch (const std::exception &e)
    {
        // Catch any exceptions thrown by std::stoi and do nothing
    }

    // Print the user's input
    std::cout << "You chose: " << userOption << std::endl;
    std::cout << " " << std::endl;

    return userOption; // Return the user's input as an integer
}

// Function to print help information
void MerkelMain::printHelp()
{
    // Print help message to the user
    std::cout << "Help. Your aim is to make money, analyze the market, make bids, and asks." << std::endl;
    std::cout << " " << std::endl;
}

void MerkelMain::printStats()
{
    // Iterate through each known product in the order book
    for (std::string const p : orderBook.getKnownProducts())
    {
        // Print the product name
        std::cout << "Product: " << p << std::endl;

        // Get all ask orders for the product at the current time
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);

        // Print the number of ask orders seen
        std::cout << "Asks seen: " << entries.size() << std::endl;

        // Print the maximum ask price
        std::cout << "Max ask: " << orderBook.getHighPrice(entries) << std::endl;

        // Print the average ask price
        std::cout << "Average ask: " << orderBook.getAvgPrice(entries) << std::endl;

        // Print the price spread
        std::cout << "Price Spread of " << orderBook.getPriceSpread(entries) << std::endl;

        // Print the minimum ask price
        std::cout << "Min ask: " << orderBook.getLowPrice(entries) << std::endl;

        // Print a blank line for separation
        std::cout << " " << std::endl;
    }
}

void MerkelMain::makeAsk()
{
    // Prompt the user to enter the ask details
    std::cout << "Make an ask - Enter the amount: product,price,amount" << std::endl;
    std::cout << "eg:" << std::endl;
    std::cout << "ETH/BTC,200,0.5" << std::endl;

    // Read the user's input
    std::string input;
    std::getline(std::cin, input);

    // Tokenize the input string based on commas
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');

    // Check if the input has exactly 3 tokens
    if (tokens.size() != 3)
    {
        std::cout << "Bad Input" << std::endl;
    }
    else
    {
        try
        {
            // Convert the tokens to an OrderBookEntry object
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],           // price
                tokens[2],           // amount
                currentTime,         // current time
                tokens[0],           // product
                OrderBookType::ask); // order type

            // Insert the order into the order book
            orderBook.insertOrder(obe);
        }
        catch (const std::exception &e)
        {
            // Print any exceptions that occur
            std::cerr << e.what() << '\n';
        }
    }

    // Print the user's input
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
    std::vector<OrderBookEntry> sales = orderBook.matchAskstoBids("ETH/BTC", currentTime);

    std::cout << "Sales size " << sales.size() << std::endl;
    for (OrderBookEntry &sale : sales)
    {
        std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;
    }

    currentTime = orderBook.getNextTime(currentTime);
}

bool MerkelMain::exit()
{
    std::cout << "Good Bye!" << std::endl;
    std::cout << " " << std::endl;

    // Close App
    return false;
}

// Function to process the option of the user and returns True, for the app to
// continue running or False to close the app, when 7 is selected.
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
        printHelp();

    // Check user input. Option 2
    if (userOption == 2)
        printStats();

    // Check user input. Option 3
    if (userOption == 3)
        makeAsk();

    // Check user input. Option 4
    if (userOption == 4)
        makeBid();

    // Check user input. Option 5
    if (userOption == 5)
        printWallet();

    // Check user input. Option 6
    if (userOption == 6)
        nextTimeFrame();

    // Check user input. Option 7
    if (userOption == 7)
        return exit();

    // Continue for valid menu options
    return true;
}