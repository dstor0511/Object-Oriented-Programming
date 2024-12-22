#pragma once
#include "WeatherEntry.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>

// The WeatherMain class handles the main functionality of the weather application
class WeatherMain
{
private:
    // Private data members can be declared here

public:
    // Constructor for the WeatherMain class
    WeatherMain();

    // Function to initialize the weather application
    void initialize();

    // Function to display the menu options to the user
    void printMenu();

    // Struct to hold the user input
    struct UserInput
    {
        std::string countryCode;
        int year;
    };

    // Function to get the user's option from the menu
    UserInput getUserOption();

    // Function to process the user's selected option
    // bool processUserOption(int option);

    // Function to exit the application
    // bool exit();

    // Function to compute and print candlestick data
    void computeAndPrintCandlestickData(const std::vector<WeatherEntry> &entries);
};
