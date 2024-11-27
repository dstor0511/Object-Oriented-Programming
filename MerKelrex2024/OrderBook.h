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

    // Returns earliest time in the OrderBook
    std::string getEarliestTime();

    // Returns the next time after the sent time in the orderBook
    std::string getNextTime(std::string timeStamp);

    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    static double getLowPrice(std::vector<OrderBookEntry> &orders);
    static double getAvgPrice(std::vector<OrderBookEntry> &orders);
    static double getPriceSpread(std::vector<OrderBookEntry> &orders);

private:
    std::vector<OrderBookEntry> orders;
};

// double MerkelMain::computePriceSpread(std::vector<OrderBookEntry> &orders)
// {
//     double lowPrice = MerkelMain::computeLowPrice(orders);
//     double highPrice = MerkelMain::computeHighPrice(orders);
//     return highPrice - lowPrice;
// }