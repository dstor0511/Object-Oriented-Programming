#include <iostream>
#include <string>
#include <vector>

#include "WeatherEntry.h"
#include "CSVReader.h"
#include "WeatherMain.h"

// The main function of the program
int main()
{
    // Create an instance of WeatherMain
    WeatherMain app{};

    // Initialize the application
    app.initialize();

    // Return 0 to indicate successful execution
    return 0;
}