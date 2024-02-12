/* ------------------------- Code written by myself  -------------------------*/

//
#pragma once

#include <string>
#include "OrderBookEntry.h"
#include <vector>
#include <map>

class Candlestick
{
public:
	// Constructor for the Candlestick class
	Candlestick(
		std::string candleTimestamp, // The timestamp of the candlestick
		double candleOpenPrice,		 // The opening price of the candlestick
		double candleHighPrice,		 // The highest price during the time period
		double candleLowPrice,		 // The lowest price during the time period
		double candleClosingPrice	 // The closing price of the candlestick
	);

	std::string candleTimestamp; // The timestamp of the candlestick
	double candleOpenPrice;		 // The opening price of the candlestick
	double candleHighPrice;		 // The highest price during the time period
	double candleLowPrice;		 // The lowest price during the time period
	double candleClosingPrice;	 // The closing price of the candlestick
};

/* ------------------------- end  -------------------------*/