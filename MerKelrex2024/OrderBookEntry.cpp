#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _price,
                               double _amount,
                               std::string _timeStamp,
                               std::string _product,
                               OrderBookType _orderType)
    : price(_price),
      amount(_amount),
      timeStamp(_timeStamp),
      product(_product),
      orderType(_orderType)
{
}