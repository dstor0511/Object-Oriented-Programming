#include <iostream>
#include <string>
#include <vector>

#include "WeatherEntry.h"
#include "CSVReader.h"

int main()
{
    std::vector<WeatherEntry> entries;

    // Test CSVReader readCSV function
    CSVReader::readCSV("weatherData.csv");
    return 0;
}