#pragma once
#include <string>

// Enum class for OrderType to limit the options of the code
enum class OrderBookType
{
    bid,
    ask,
    unknown,
    sale
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

    // Function to convert a string to an OrderBookType
    static OrderBookType stringToOrderBookType(std::string s);

    double price;
    double amount;
    std::string timeStamp;
    std::string product;
    OrderBookType orderType;

    static bool compareByTimeStamp(OrderBookEntry &e1, OrderBookEntry &e2)
    {
        return e1.timeStamp < e2.timeStamp;
    }

    static bool compareByPriceAsc(OrderBookEntry &e1, OrderBookEntry &e2)
    {
        return e1.price < e2.price;
    }

    static bool compareByPriceDesc(OrderBookEntry &e1, OrderBookEntry &e2)
    {
        return e1.price > e2.price;
    }
};