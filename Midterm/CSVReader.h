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
    static WeatherEntry stringsToOBE(std::string _time,
                                     double _atTemperature,
                                     double _beTemperature,
                                     double _bgTemperature,
                                     double _chTemperature,
                                     double _czTemperature,
                                     double _deTemperature,
                                     double _dkTemperature,
                                     double _eeTemperature,
                                     double _esTemperature,
                                     double _fiTemperature,
                                     double _frTemperature,
                                     double _gbTemperature,
                                     double _grTemperature,
                                     double _hrTemperature,
                                     double _huTemperature,
                                     double _ieTemperature,
                                     double _itTemperature,
                                     double _ltTemperature,
                                     double _luTemperature,
                                     double _lvTemperature,
                                     double _nlTemperature,
                                     double _noTemperature,
                                     double _plTemperature,
                                     double _ptTemperature,
                                     double _roTemperature,
                                     double _seTemperature,
                                     double _siTemperature,
                                     double _skTemperature);

private:
    // Function to convert a vector of strings to an OrderBookEntry object
    static WeatherEntry stringsToOBE(std::vector<std::string> strings);
};