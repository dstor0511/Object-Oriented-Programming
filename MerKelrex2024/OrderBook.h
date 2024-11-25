#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <map>

class OrderBook
{
public:
    // Constructor, reading a csv data file
    OrderBook(std::string filename);

    // vector of all known products in the data set
    std::vector<std::string> getKnownProducts();

    // return vector of orders according to the sent filters
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);

    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    static double getLowPrice(std::vector<OrderBookEntry> &orders);

private:
    std::vector<OrderBookEntry> orders;
};

// // Stats functions
// double MerkelMain::computeAveragePrice(std::vector<OrderBookEntry> &orders)
// {
//     double totalPrice = 0;
//     for (const auto &order : orders)
//     {
//         totalPrice += order.price;
//     }
//     return totalPrice / orders.size();
// }

// double MerkelMain::computeLowPrice(std::vector<OrderBookEntry> &orders)
// {
//     double lowPrice = orders[0].price; // Start with the first order
//     for (const auto &order : orders)
//     {
//         if (order.price < lowPrice)
//         {
//             lowPrice = order.price;
//         }
//     }
//     return lowPrice;
// }

// double MerkelMain::computeHighPrice(std::vector<OrderBookEntry> &orders)
// {
//     double highPrice = orders[0].price; // Start with the first order
//     for (const auto &order : orders)
//     {
//         if (order.price > highPrice)
//         {
//             highPrice = order.price;
//         }
//     }
//     return highPrice;
// }

// double MerkelMain::computePriceSpread(std::vector<OrderBookEntry> &orders)
// {
//     double lowPrice = MerkelMain::computeLowPrice(orders);
//     double highPrice = MerkelMain::computeHighPrice(orders);
//     return highPrice - lowPrice;
// }