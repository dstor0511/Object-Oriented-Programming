#include "CSVReader.h"
#include <fstream>
#include <iostream>

// Constructor for CSVReader
CSVReader::CSVReader() {

};

// Read the CSV file and return a vector of WeatherEntry objects
std::vector<WeatherEntry> CSVReader::readCSV(std::string file)
{
    std::vector<WeatherEntry> entries;
    std::ifstream csvFile{file};
    std::string line;

    // Check if the file is open
    if (csvFile.is_open())
    {
        // Read the file line by line
        while (std::getline(csvFile, line))
        {
            // Convert the line to an OrderBookEntry object
            WeatherEntry e = stringsToOBE(tokenise(line, ','));
            entries.push_back(e);
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
WeatherEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double atTemperature;
    double beTemperature;
    double bgTemperature;
    double chTemperature;
    double czTemperature;
    double deTemperature;
    double dkTemperature;
    double eeTemperature;
    double esTemperature;
    double fiTemperature;
    double frTemperature;
    double gbTemperature;
    double grTemperature;
    double hrTemperature;
    double huTemperature;
    double ieTemperature;
    double itTemperature;
    double ltTemperature;
    double luTemperature;
    double lvTemperature;
    double nlTemperature;
    double noTemperature;
    double plTemperature;
    double ptTemperature;
    double roTemperature;
    double seTemperature;
    double siTemperature;
    double skTemperature;

    if (tokens.size() != 29)
    {
        std::cout << "Bad line" << std::endl;
        std::cout << tokens[0] << std::endl;
        throw std::exception{};
    }

    try
    {
        for (size_t i = 1; i <= 28; ++i)
        {
            try
            {
                double value = std::stod(tokens[i]);
                // Assign the value to the corresponding variable
                switch (i)
                {
                case 1:
                    atTemperature = value;
                    break;
                case 2:
                    beTemperature = value;
                    break;
                case 3:
                    bgTemperature = value;
                    break;
                case 4:
                    chTemperature = value;
                    break;
                case 5:
                    czTemperature = value;
                    break;
                case 6:
                    deTemperature = value;
                    break;
                case 7:
                    dkTemperature = value;
                    break;
                case 8:
                    eeTemperature = value;
                    break;
                case 9:
                    esTemperature = value;
                    break;
                case 10:
                    fiTemperature = value;
                    break;
                case 11:
                    frTemperature = value;
                    break;
                case 12:
                    gbTemperature = value;
                    break;
                case 13:
                    grTemperature = value;
                    break;
                case 14:
                    hrTemperature = value;
                    break;
                case 15:
                    huTemperature = value;
                    break;
                case 16:
                    ieTemperature = value;
                    break;
                case 17:
                    itTemperature = value;
                    break;
                case 18:
                    ltTemperature = value;
                    break;
                case 19:
                    luTemperature = value;
                    break;
                case 20:
                    lvTemperature = value;
                    break;
                case 21:
                    nlTemperature = value;
                    break;
                case 22:
                    noTemperature = value;
                    break;
                case 23:
                    plTemperature = value;
                    break;
                case 24:
                    ptTemperature = value;
                    break;
                case 25:
                    roTemperature = value;
                    break;
                case 26:
                    seTemperature = value;
                    break;
                case 27:
                    siTemperature = value;
                    break;
                case 28:
                    skTemperature = value;
                    break;
                }
            }
            catch (const std::exception &e)
            {
                // Print an error message if the conversion fails
                std::cerr << "Error at line " << __LINE__ << ": " << e.what() << " Token: " << tokens[i] << std::endl;
                continue;
            }
        }
    }
    catch (const std::exception &e)
    {
        // Print an error message if the conversion fails
        std::cerr << "Error: " << e.what() << std::endl;
        throw;
    }

    // Create an WeatherEntry object using the parsed values
    WeatherEntry e{tokens[0], atTemperature, beTemperature, bgTemperature, chTemperature, czTemperature, deTemperature, dkTemperature, eeTemperature, esTemperature, fiTemperature, frTemperature, gbTemperature, grTemperature, hrTemperature, huTemperature, ieTemperature, itTemperature, ltTemperature, luTemperature, lvTemperature, nlTemperature, noTemperature, plTemperature, ptTemperature, roTemperature, seTemperature, siTemperature, skTemperature};
    return e;
};
