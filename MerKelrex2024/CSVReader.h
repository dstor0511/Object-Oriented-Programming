#pragma once
#include <string>
#include <vector>
#include "OrderBookEntry.h"

// Class to read and parse CSV files
class CSVReader
{
public:
  // Constructor for CSVReader
  CSVReader();

  // Function to read a CSV file and return a vector of OrderBookEntry objects
  static std::vector<OrderBookEntry> readCSV(std::string csvFile);

  // Function to split a CSV line into tokens based on the separator
  static std::vector<std::string> tokenise(std::string csvLine, char separator);

  // Function to convert strings to an OrderBookEntry object
  static OrderBookEntry stringsToOBE(std::string price, std::string amount, std::string timeStamp, std::string product, OrderBookType OrderBookType);

private:
  // Function to convert a vector of strings to an OrderBookEntry object
  static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
};