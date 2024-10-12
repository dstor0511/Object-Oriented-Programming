// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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

int main()
{
    // Status of the app
    bool status = true;

    while (status)
    {

        // Print Menu Funct.
        printMenu();

        // Request and receive user option
        int userOption = getUserOption();

        // Run the app and process the user option
        status = processUserOption(userOption);
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


