// ConsoleApplication1.cpp : This file contains the 'main' function. Program
// execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>

#include "CSVReader.h"
#include "MerkelMain.h"
#include "OrderBookEntry.h"

// The main function of the program
int main()
{
  // Create an instance of MerkelMain
  MerkelMain app{};

  // Initialize the application
  app.init();

  // Return 0 to indicate successful execution
  return 0;
}