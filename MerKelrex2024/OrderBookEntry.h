#pragma once
#include <string>

// Enum class for OrderType to limit the options of the code
enum class OrderBookType
{
    bid,
    ask
};

// OrderBookEntry class to store a full row of data
class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timeStamp,
                   std::string _product,
                   OrderBookType _orderType);

    double price;
    double amount;
    std::string timeStamp;
    std::string product;
    OrderBookType orderType;
};