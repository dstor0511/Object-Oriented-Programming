// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"

int main()
{
    MerkelMain app{};
    app.init();

    return 0;
}
// std::vector<double> prices;
// std::vector<double> amounts;
// std::vector<std::string> timeStamps;
// std::vector<std::string> product;
// std::vector<OrderBookType> orderTypes;