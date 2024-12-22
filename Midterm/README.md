# Midterm for OOP 2024-2

In this document, I'll document any relevant information about the project and its progress.

Dec 14-15.

-   These days I created the Gantt charts that would dictate the order in which things would be developed in a timely and orderly manner. Gantt charts can be found in Google Drive.

Dec 16.

-   Added the WeatherEntry class. I used a single line of the file as my target, keeping in mind that I'll need to run stats on this vector.
-   Laid out the header file for the CSVReader class, this will help us tokenize each line and have the desired "entries" vector.

Dec 20

-   Started trying to make the CSVReader class read the testdata.csv file, but it wasn't reading anything. Not sure why.
-   It is working now, but only for the testdata.csv file. The main file is returning the error:

` 
    Error: stod
    terminate called after throwing an instance of 'std::invalid_argument'
    what(): stod
    Aborted (core dumped)`

-   Finally, the CSVReader started working as expected. There is an error in line 206, not sure what the error is, but most of the file is working as expected. No other issues, sprint completed successfully.

-   Improvements to the efficiency can be made, specially with 28 variables to work with, but we can do that later. :)

Dec 22

- Addition of WeatherMain Class:
- WeatherMain : Introduced the WeatherMain class and implementation to handle the main functionality of the weather application, including methods for initialization, displaying menu options, getting user input, and computing candlestick data for weather entries. 

- Integration of WeatherMain Class:
- main.cpp: Updated the main function to create an instance of WeatherMain, initialize the application, and compute and print candlestick data using the weather entries read from the CSV file.

- Improvements to CSVReader Class:
- Midterm/CSVReader.cpp: Enhanced error handling in the stringsToOBE method by adding a continue statement to skip over invalid tokens during the conversion process.
