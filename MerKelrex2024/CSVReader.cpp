#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader() {

};

std::vector<OrderBookEntry> CSVReader::readCSV(std::string file)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{file};
    std::string line;

    if (csvFile.is_open())
    {
        while (std::getline(csvFile, line))
        {
            OrderBookEntry obe = strinsToOBE(tokenise(line, ','));
            entries.push_back(obe);
        }
    }

    std::cout << "CSVReader::readCSV read " << entries.size() << std::endl;

    return entries;
};

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens; // Vector to hold the tokens extracted from the CSV line

    signed int start, end; // Variables to track the start and end indices of tokens
    std::string token;     // Variable to hold the current token

    // Find the index of the first character that is not the separator
    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        // Find the next occurrence of the separator starting from 'start'
        end = csvLine.find_first_of(separator, start);

        // If 'start' reaches the end of the string or if 'start' equals 'end', exit the loop
        if (start == csvLine.length() || start == end)
            break;

        // Extract the token from the string
        if (end >= 0)
            token = csvLine.substr(start, end - start); // Token from 'start' to 'end'
        else
            token = csvLine.substr(start, csvLine.length() - start); // Token to the end of the string

        tokens.push_back(token); // Add the extracted token to the vector
        start = end + 1;         // Move 'start' to the next character after the current separator
    } while (end > 0); // Continue until no more separators are found

    return tokens;
};

OrderBookEntry CSVReader::strinsToOBE(std::vector<std::string> tokens)
{

    double price;
    double amount;
    if (tokens.size() != 5)
    {
        std::cout << "Bad line" << std::endl;
        std::cout << tokens[0] << std::endl;
        throw std::exception{};
    }

    // convert string to double for the last two tokens of each line
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
        std::cout << "Bad float!" << tokens[3] << std::endl;
        std::cout << "Bad float!" << tokens[4] << std::endl;
        throw;
    }

    OrderBookEntry obe{price,
                       amount,
                       tokens[0],
                       tokens[1],
                       OrderBookEntry::stringToOrderBookType(tokens[2])};

    return obe;
};
