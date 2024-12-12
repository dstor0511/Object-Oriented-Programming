#include "CSVReader.h"
#include <fstream>
#include <iostream>

// Constructor for CSVReader
CSVReader::CSVReader() {

};

// Read the CSV file and return a vector of OrderBookEntry objects
std::vector<OrderBookEntry> CSVReader::readCSV(std::string file)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{file};
    std::string line;

    // Check if the file is open
    if (csvFile.is_open())
    {
        // Read the file line by line
        while (std::getline(csvFile, line))
        {
            // Convert the line to an OrderBookEntry object
            OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
            entries.push_back(obe);
        }
    }

    // Print the number of entries read
    std::cout << "CSVReader::readCSV read " << entries.size() << std::endl;

    return entries;
};

// Function to split a CSV line into tokens based on the separator
std::vector<std::string> CSVReader::tokenise(std::string csvLine,
                                             char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;

    // Find the first character that is not the separator
    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        // Find the next separator character
        end = csvLine.find_first_of(separator, start);

        // If start is at the end of the line or no more separators are found, break
        if (start == csvLine.length() || start == end)
            break;

        if (end >= 0)
            token = csvLine.substr(start, end - start);
        else
            token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);

    return tokens;
};

// Function to convert a vector of strings to an OrderBookEntry object
OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double price;
    double amount;
    if (tokens.size() != 5)
    {
        std::cout << "Bad line" << std::endl;
        std::cout << tokens[0] << std::endl;
        throw std::exception{};
    }

    try
    {
        // Convert the price and amount to double
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
        // Print an error message if the conversion fails
        std::cout << "Bad float!" << tokens[3] << std::endl;
        std::cout << "Bad float!" << tokens[4] << std::endl;
        throw;
    }

    // Create an OrderBookEntry object using the parsed values
    OrderBookEntry obe{price, amount, tokens[0], tokens[1],
                       OrderBookEntry::stringToOrderBookType(tokens[2])};

    // Return the OrderBookEntry object
    return obe;
};

// Function to convert strings to an OrderBookEntry object
OrderBookEntry CSVReader::stringsToOBE(std::string priceString, std::string amountString, std::string timeStamp, std::string product, OrderBookType orderType)
{
    double price, amount;
    try
    {
        // Convert price and amount strings to double

        price = std::stod(priceString);
        amount = std::stod(amountString);
    }
    catch (const std::exception &e)
    {
        // Print error messages if conversion fails

        std::cout << "CSVReader::stringsToOBE Bad float!" << priceString << std::endl;
        std::cout << "CSVReader::stringsToOBE Bad float!" << amountString << std::endl;
        throw;
    }

    // Create an OrderBookEntry object using the converted values
    OrderBookEntry obe{price, amount, timeStamp, product, orderType};

    return obe;
};
