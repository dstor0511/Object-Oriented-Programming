#include "OrderBook.h"
#include "CSVReader.h"
#include <algorithm>
#include "OrderBookEntry.h"

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
};

std::vector<std::string> OrderBook::getKnownProducts()
{

    std::vector<std::string> products;

    std::map<std::string, bool> prodMap;

    for (OrderBookEntry &e : orders)
    {
        prodMap[e.product] = true;
    }

    for (auto const &e : prodMap)
    {
        products.push_back(e.first);
    }

    return products;
};

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{

    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry &e : orders)
    {
        if (e.orderType == type &&
            e.product == product &&
            e.timeStamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
};

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders)
{
    double max = orders[0].price;

    for (OrderBookEntry &e : orders)
    {
        if (e.price > max)
            max = e.price;
    };
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders)
{
    double min = orders[0].price;

    for (OrderBookEntry &e : orders)
    {
        if (e.price < min)
            min = e.price;
    };
    return min;
}

// This function iterates through the provided vector of `OrderBookEntry` objects,
// sums up their prices, and then divides the total by the number
// of orders to compute the average price.

double OrderBook::getAvgPrice(std::vector<OrderBookEntry> &orders)
{
    double totalPrice = 0;
    for (OrderBookEntry &e : orders)
    {
        totalPrice += e.price;
    }
    return totalPrice / orders.size();
}

// This function iterates through the provided vector of `OrderBookEntry`
// objects to find the minimum and maximum prices.
// It then calculates the spread by subtracting the minimum price from the maximum price.

double OrderBook::getPriceSpread(std::vector<OrderBookEntry> &orders)
{
    double minPrice = orders[0].price;
    double maxPrice = orders[0].price;

    for (OrderBookEntry &e : orders)
    {
        if (e.price < minPrice)
        {
            minPrice = e.price;
        }
        if (e.price > maxPrice)
        {
            maxPrice = e.price;
        }
    }

    return maxPrice - minPrice;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timeStamp;
}

std::string OrderBook::getNextTime(std::string timeStamp)
{
    std::string next_timestamp = "";

    for (OrderBookEntry &e : orders)
    {
        if (e.timeStamp > timeStamp)
        {
            next_timestamp = e.timeStamp;
            break;
        };
    }
    if (next_timestamp == "")
    {
        next_timestamp = orders[0].timeStamp;
    }
    return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry &order)
{
    orders.push_back(order);

    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimeStamp);
}

std::vector<OrderBookEntry> OrderBook::matchAskstoBids(std::string product, std::string timeStamp)
{
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timeStamp);

    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timeStamp);

    std::vector<OrderBookEntry> sales;

    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    for (OrderBookEntry &ask : asks)
    {
        for (OrderBookEntry &bid : bids)
        {

            if (bid.price >= ask.price)
            {
                OrderBookEntry sale{ask.price,
                                    0,
                                    timeStamp,
                                    product,
                                    OrderBookType::sale};

                if (bid.amount == ask.amount)
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;

                    break;
                }

                if (bid.amount > ask.amount)
                {

                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount;
                    break;
                }

                if (bid.amount < ask.amount)
                {

                    sale.amount = bid.amount;
                    sales.push_back(sale);

                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }
        }
    }
    return sales;
}