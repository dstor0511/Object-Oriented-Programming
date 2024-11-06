#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Function to tokenize a CSV line based on a specified separator character
std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens; // Vector to hold the tokens extracted from the CSV line

    signed int start, end; // Variables to track the start and end indices of tokens
    std::string token;     // Variable to hold the current token

    // Find the index of the first character that is not the separator
    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        // Find the next occurrence of the separator starting from 'start'
        end = csvLine.find_first_of(separator, start);

        // If 'start' reaches the end of the string or if 'start' equals 'end', exit the loop
        if (start == csvLine.length() || start == end)
            break;

        // Extract the token from the string
        if (end >= 0)
            token = csvLine.substr(start, end - start); // Token from 'start' to 'end'
        else
            token = csvLine.substr(start, csvLine.length() - start); // Token to the end of the string

        tokens.push_back(token); // Add the extracted token to the vector
        start = end + 1;         // Move 'start' to the next character after the current separator
    } while (end > 0); // Continue until no more separators are found

    return tokens;
}

int main()
{
    // std::vector<std::string> tokens;
    // std::string s = "10000,0.52,2024/17/05 17:52:24.884492,BTC/USDT,OrderBookType::bid";
    // tokens = tokenize(s, ',');

    // for (std::string &token : tokens)
    // {
    //     std::cout << token << std::endl;
    // }

    std::ifstream csvFile{"dataFile.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if (csvFile.is_open())
    {
        std::cout << "File Open" << std::endl;

        while (std::getline(csvFile, line))
        {
            std::cout << "Read Line: " << line << std::endl;
            tokens = tokenise(line, ',');

            if (tokens.size() != 5)
            {
                std::cout << "Bad line" << std::endl;
                continue;
            }

            // convert string to double for the last two tokens of each line
            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);

                std::cout << price << ":" << amount << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "Bad float!" << tokens[3] << std::endl;
                std::cout << "Bad float!" << tokens[4] << std::endl;

                break;
            }
        }
        csvFile.close();
    }
    else
    {
        std::cout << "Couldn't open file" << std::endl;
    }

    return 0;
}
