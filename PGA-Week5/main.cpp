#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "PassengerEntry.h"

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
    std::ifstream csvFile{"train_and_test2.csv"};
    std::string line;
    std::vector<std::string> tokens;
    int readLines = 0;

    if (csvFile.is_open())
    {
        std::cout << "File Open" << std::endl;

        while (std::getline(csvFile, line))
        {
            // std::cout << "Read Line: " << line << std::endl;
            tokens = tokenise(line, ',');

            if (tokens.size() != 9)
            {
                std::cout << "Bad line" << std::endl;
                continue;
            }

            // convert string to double for the last two tokens of each line
            try
            {

                int id = std::stoi(tokens[0]);
                int age = std::stoi(tokens[1]);
                float fare = std::stof(tokens[2]);
                int sex = std::stoi(tokens[3]);
                int sibsp = std::stoi(tokens[4]);
                int parch = std::stoi(tokens[5]);
                int pclass = std::stoi(tokens[6]);
                int embarked = std::stoi(tokens[7]);
                int survived = std::stoi(tokens[8]);
            }
            catch (const std::exception &e)
            {
                std::cout << "Bad int!" << tokens[0] << std::endl;
                std::cout << "Bad int!" << tokens[1] << std::endl;
                std::cout << "Bad int!" << tokens[2] << std::endl;
                std::cout << "Bad int!" << tokens[3] << std::endl;
                std::cout << "Bad int!" << tokens[4] << std::endl;
                std::cout << "Bad int!" << tokens[5] << std::endl;
                std::cout << "Bad int!" << tokens[6] << std::endl;
                std::cout << "Bad int!" << tokens[7] << std::endl;
                std::cout << "Bad int!" << tokens[8] << std::endl;

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