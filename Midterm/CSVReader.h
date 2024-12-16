#pragma once
#include <string>
#include <vector>
#include "WeatherEntry.h"

// Class to read and parse CSV files
class CSVReader
{
public:
    // Constructor for CSVReader
    CSVReader();

    // Function to read a CSV file and return a vector of OrderBookEntry objects
    static std::vector<WeatherEntry> readCSV(std::string csvFile);

    // Function to split a CSV line into tokens based on the separator
    static std::vector<std::string> tokenise(std::string csvLine, char separator);

    // Function to convert strings to an OrderBookEntry object
    // static WeatherEntry stringsToOBE(std::string price, std::string amount, std::string timeStamp, std::string product, OrderBookType OrderBookType);

private:
    // Function to convert a vector of strings to an OrderBookEntry object
    static WeatherEntry stringsToOBE(std::vector<std::string> strings);
};