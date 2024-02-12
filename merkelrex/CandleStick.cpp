/* ------------------------- Code written by myself  -------------------------*/

#include "CandleStick.h"
#include <string>
#include <vector>

// Constructor for the Candlestick class
Candlestick::Candlestick(
    std::string candleTimestamp, // The timestamp of the candlestick
    double candleOpenPrice,      // The opening price of the candlestick
    double candleHighPrice,      // The highest price during the time period
    double candleLowPrice,       // The lowest price during the time period
    double candleClosingPrice    // The closing price of the candlestick
    )
    : candleTimestamp(candleTimestamp),      // Initialize the candleTimestamp member variable with the provided value
      candleOpenPrice(candleOpenPrice),      // Initialize the candleOpenPrice member variable with the provided value
      candleHighPrice(candleHighPrice),      // Initialize the candleHighPrice member variable with the provided value
      candleLowPrice(candleLowPrice),        // Initialize the candleLowPrice member variable with the provided value
      candleClosingPrice(candleClosingPrice) // Initialize the candleClosingPrice member variable with the provided value
{
}

/* ------------------------- end  -------------------------*/