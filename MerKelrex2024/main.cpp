// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

int main()
{
    MerkelMain app {};
    app.printMenu();

    
    return 0;
}
    // std::vector<double> prices;
    // std::vector<double> amounts;
    // std::vector<std::string> timeStamps;
    // std::vector<std::string> product;
    // std::vector<OrderBookType> orderTypes;

    // // Status of the app
    // bool status = true;

    // while (status)
    // {

    //     // Print Menu Funct.
    //     printMenu();

    //     // Request and receive user option
    //     int userOption = getUserOption();

    //     // Run the app and process the user option
    //     status = processUserOption(userOption);
    // }

    // std::vector<OrderBookEntry> orders;

    // orders.push_back(OrderBookEntry{10000, 0.52, "2024/17/05 17:52:24.884492", "BTC/USDT", OrderBookType::bid});
    // orders.push_back(OrderBookEntry{300, 0.99, "2024/10/06 19:32:24.872592", "BTC/ETH", OrderBookType::bid});
    // orders.push_back(OrderBookEntry{2200, 0.31, "2024/17/10 22:11:24.358492", "ETH/BTC", OrderBookType::ask});
    // orders.push_back(OrderBookEntry{10000, 0.52, "2024/17/05 17:52:24.884492", "BTC/USDT", OrderBookType::bid});
    // orders.push_back(OrderBookEntry{10020, 0.75, "2024/17/05 17:53:45.112233", "BTC/USDT", OrderBookType::ask});
    // orders.push_back(OrderBookEntry{9995, 0.40, "2024/17/05 17:54:11.987654", "BTC/USDT", OrderBookType::bid});
    // orders.push_back(OrderBookEntry{10010, 1.00, "2024/17/05 17:55:23.456789", "BTC/USDT", OrderBookType::ask});
    // orders.push_back(OrderBookEntry{10050, 0.32, "2024/17/05 17:56:07.123456", "BTC/USDT", OrderBookType::ask});
    // orders.push_back(OrderBookEntry{9980, 0.85, "2024/17/05 17:57:30.654321", "BTC/USDT", OrderBookType::bid});

    // for (OrderBookEntry &order : orders)
    // {
    //     std::cout << "The price is: " << order.price << std::endl;
    // }

    // // Call functions to compute the statistics
    // std::cout << "Average Price: " << computeAveragePrice(orders) << std::endl;
    // std::cout << "Low Price: " << computeLowPrice(orders) << std::endl;
    // std::cout << "High Price: " << computeHighPrice(orders) << std::endl;
    // std::cout << "Price Spread: " << computePriceSpread(orders) << std::endl;

