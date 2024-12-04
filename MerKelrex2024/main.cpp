// ConsoleApplication1.cpp : This file contains the 'main' function. Program
// execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>

#include "CSVReader.h"
#include "MerkelMain.h"
#include "OrderBookEntry.h"

int main() {
  MerkelMain app{};
  app.init();

  return 0;
}


// This is a test comment to commit in git 