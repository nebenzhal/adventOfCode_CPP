#include <iostream>
#include <fstream>
#include <map>

int main()
{
    std::ifstream file("input2.txt");
    std::string newLine;
    int totalScore = 0;

    // why char and not int?

    const std::map<char, char> choices = {
        {'X', '1'},
        {'Y', '2'},
        {'Z', '3'}};

    const std::map<char, char> loses = {
        {'A', 'Z'},
        {'B', 'X'},
        {'C', 'Y'}};

    while (!file.eof())
    {
        while (getline(file, newLine))
        {
            totalScore += (choices.at(newLine[2])) - '0';
            if (((choices.at(newLine[2])) - '0') == (int(newLine[0]) - '0' - 16))
                totalScore += 3; // If its a tie
            else if (newLine[2] == loses.at(newLine[0]))
                break;
            else
                totalScore += 6;
        }
    }
    std::cout << totalScore << '\n';
};
