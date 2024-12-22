#include "WeatherMain.h"

// Constructor for WeatherMain
WeatherMain::WeatherMain() {}

void WeatherMain::initialize()
{
    std::string input;
    // Set the current time to the earliest time in the order book
    // currentTime = orderBook.getEarliestTime();
    bool status = true;
    while (status)
    {
        // Display the menu options
        printMenu();
        // Get the user's option
        getUserOption();
    }
}

// Function to display the options offered to the use
void WeatherMain::printMenu()
{
    // 1 print help
    std::cout << "Welcome to the weather app" << std::endl;

    // std::cout << "Current Time is: " << currentTime << std::endl;
}

// Function to receive the input of the user for the main menu
WeatherMain::UserInput WeatherMain::getUserOption()
{
    WeatherMain::UserInput input;

    // Request the user for the country code
    std::cout << "Type in the country code in uppercase for any of the 29 countries in the EU." << std::endl;
    std::getline(std::cin, input.countryCode); // Read the user's input as a string

    // Print the user's input
    std::cout << "You chose: " << input.countryCode << std::endl;

    // Request the user for the year
    std::cout << "Type in a year between 1980 and 2019." << std::endl;
    std::cin >> input.year;

    // Validate the year input
    while (input.year < 1980 || input.year > 2019)
    {
        std::cout << "Invalid year. Please enter a year between 1980 and 2019." << std::endl;
        std::cin >> input.year;
    }

    // Print the user's input
    std::cout << "You chose the year: " << input.year << std::endl;
    std::cout << " " << std::endl;

    return input; // Return the user's input
}
/*
void WeatherMain::computeAndPrintCandlestickData(const std::vector<WeatherEntry> &entries)
{
    std::map<int, std::vector<double>> yearlyTemperatures;

    // Group temperatures by year
    for (const auto &entry : entries)
    {
        try
        {
            int year = std::stoi(entry.time.substr(0, 4)); // Extract year from the time string
            yearlyTemperatures[year].push_back(entry.atTemperature);
            // Add other temperatures if needed
        }
        catch (const std::exception &e)
        {
            // Print an error message if the conversion fails
            std::cerr << "Error at line " << __LINE__ << ": " << e.what() << std::endl;
            continue;
        }
    }

    // Compute and print candlestick data for each year
    for (const auto &[year, temperatures] : yearlyTemperatures)
    {
        if (temperatures.empty())
            continue;

        double open = temperatures.front();
        double close = temperatures.back();
        double high = *std::max_element(temperatures.begin(), temperatures.end());
        double low = *std::min_element(temperatures.begin(), temperatures.end());

        std::cout << "Year: " << year << std::endl;
        std::cout << "Open: " << open << ", High: " << high << ", Low: " << low << ", Close: " << close << std::endl;
        std::cout << "--------------------" << std::endl;
    }
}
*/

void WeatherMain::computeAndPrintCandlestickData(const std::vector<WeatherEntry> &entries)
{
    // Create a map of countries, each with a map of yearly temperatures
    std::map<std::string, std::map<int, std::vector<double>>> countryYearlyTemperatures;

    // List of country codes corresponding to the temperature fields
    std::vector<std::string> countries = {
        "AT", "BE", "BG", "CH", "CZ", "DE", "DK", "EE", "ES", "FI",
        "FR", "GB", "GR", "HR", "HU", "IE", "IT", "LT", "LU", "LV",
        "NL", "NO", "PL", "PT", "RO", "SE", "SI", "SK"};

    // Group temperatures by country and year
    for (const auto &entry : entries)
    {
        try
        {
            // Extract the year from the UTC timestamp (assuming it's in the format "YYYY-MM-DDTHH:MM:SSZ")
            int year = std::stoi(entry.time.substr(0, 4));

            // Loop through each country and add the corresponding temperature to the map
            for (const auto &country : countries)
            {
                // Get the temperature for the current country
                double temperature = 0.0;
                if (country == "AT")
                    temperature = entry.atTemperature;
                else if (country == "BE")
                    temperature = entry.beTemperature;
                else if (country == "BG")
                    temperature = entry.bgTemperature;
                else if (country == "CH")
                    temperature = entry.chTemperature;
                else if (country == "CZ")
                    temperature = entry.czTemperature;
                else if (country == "DE")
                    temperature = entry.deTemperature;
                else if (country == "DK")
                    temperature = entry.dkTemperature;
                else if (country == "EE")
                    temperature = entry.eeTemperature;
                else if (country == "ES")
                    temperature = entry.esTemperature;
                else if (country == "FI")
                    temperature = entry.fiTemperature;
                else if (country == "FR")
                    temperature = entry.frTemperature;
                else if (country == "GB")
                    temperature = entry.gbTemperature;
                else if (country == "GR")
                    temperature = entry.grTemperature;
                else if (country == "HR")
                    temperature = entry.hrTemperature;
                else if (country == "HU")
                    temperature = entry.huTemperature;
                else if (country == "IE")
                    temperature = entry.ieTemperature;
                else if (country == "IT")
                    temperature = entry.itTemperature;
                else if (country == "LT")
                    temperature = entry.ltTemperature;
                else if (country == "LU")
                    temperature = entry.luTemperature;
                else if (country == "LV")
                    temperature = entry.lvTemperature;
                else if (country == "NL")
                    temperature = entry.nlTemperature;
                else if (country == "NO")
                    temperature = entry.noTemperature;
                else if (country == "PL")
                    temperature = entry.plTemperature;
                else if (country == "PT")
                    temperature = entry.ptTemperature;
                else if (country == "RO")
                    temperature = entry.roTemperature;
                else if (country == "SE")
                    temperature = entry.seTemperature;
                else if (country == "SI")
                    temperature = entry.siTemperature;
                else if (country == "SK")
                    temperature = entry.skTemperature;

                // Add the temperature for the current country and year
                countryYearlyTemperatures[country][year].push_back(temperature);
            }
        }
        catch (const std::exception &e)
        {
            // Print an error message if the conversion fails
            std::cerr << "Error at line " << __LINE__ << ": " << e.what() << std::endl;
            continue;
        }
    }

    // Compute and print candlestick data for each country and each year
    for (const auto &[country, yearlyTemperatures] : countryYearlyTemperatures)
    {
        std::cout << "Country: " << country << std::endl;

        for (const auto &[year, temperatures] : yearlyTemperatures)
        {
            if (temperatures.empty())
            {
                continue;
            }

            double high = *std::max_element(temperatures.begin(), temperatures.end());
            double low = *std::min_element(temperatures.begin(), temperatures.end());
            // Calculate the average mean temperature for the current time frame (close)
            double sumCurrent = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
            double close = sumCurrent / temperatures.size();

            // Calculate the average mean temperature for the previous time frame (open)
            double open = 0.0;
            // if (yearlyTemperatures.find(year - 1) != yearlyTemperatures.end())
            // {
            //     const auto &prevTemperatures = yearlyTemperatures[year - 1][i];
            //     if (!prevTemperatures.empty())
            //     {
            //         double sumPrevious = std::accumulate(prevTemperatures.begin(), prevTemperatures.end(), 0.0);
            //         open = sumPrevious / prevTemperatures.size();
            //     }
            // }

            std::cout << "Year: " << year << std::endl;
            std::cout << "Open: " << open << ", High: " << high << ", Low: " << low << ", Close: " << close << std::endl;
            std::cout << "--------------------" << std::endl;
        }
    }
}
