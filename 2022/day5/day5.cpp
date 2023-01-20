#include <iostream>
#include <fstream>
#include <regex>

std::vector<std::vector<char>> initStateLoader(std::ifstream &file, const int len)
{
    std::string line;
    std::regex rx("[a-zA-Z]+");

    std::vector<std::vector<char>> chars(len + 1);

    while (getline(file, line) && !line.empty())
    {
        for (auto iter = std::sregex_iterator(line.begin(), line.end(), rx); iter != std::sregex_iterator(); ++iter)
        {
            chars[0.25 * iter->position() + 0.25].push_back((line[iter->position()]));
        }
    }
    for (int i = 0; i < (len + 1); ++i)
        std::reverse(chars[i].begin(), chars[i].end());
    return chars;
}

std::vector<int> commandParser(std::string &command)
{
    static std::vector<int> commandVals(3);
    commandVals[0] = stoi(command.substr(command.find("move") + 5, command.find("from") - 5));
    commandVals[1] = stoi(command.substr(command.find("from") + 5, command.find("to") - 5)) - 1;
    commandVals[2] = stoi(command.substr(command.find("to") + 2, command.length() - 5)) - 1;

    return commandVals;
};

void moover(std::vector<char> &startingPosition, std::vector<char> &endingPosition, int &amountToBeMoved)
{
    for (int i = 0; i < amountToBeMoved; i++)
    {
        endingPosition.push_back(startingPosition.back());
        startingPosition.pop_back();
    }
}
void multiMoover(std::vector<char> &startingPosition, std::vector<char> &endingPosition, int &amountToBeMoved) // pt2
{
    for (int i = amountToBeMoved; i > 0; --i)
    {
        endingPosition.push_back(startingPosition[startingPosition.size() - i]);
    }
    for (int i = 0; i < amountToBeMoved; i++)
    {
        startingPosition.pop_back();
    }
}

void printPos(std::vector<std::vector<char>> &positions)
{
    for (int i = 0; i < positions.size(); ++i)
    {
        for (char c : positions[i])
            std::cout << c << " | ";
        std::cout << '\n';
    }
}

std::string part1(std::ifstream &file, std::vector<std::vector<char>> &positions)
{
    std::string line;
    std::string finalMessage = "";
    printPos(positions);

    while (getline(file, line))
    {
        std::vector<int> commands = commandParser(line);
        moover(positions[commands[1]], positions[commands[2]], commands[0]);
    }
    printPos(positions);

    for (int i = 0; i < positions.size() - 1; ++i)
    {
        finalMessage += (positions[i].back());
    }
    return finalMessage;
}

std::string part2(std::ifstream &file, std::vector<std::vector<char>> &positions)
{
    std::string line;
    std::string finalMessage = "";

    while (getline(file, line))
    {
        printPos(positions);
        std::vector<int> commands = commandParser(line);
        multiMoover(positions[commands[1]], positions[commands[2]], commands[0]);
    }
    printPos(positions);

    for (int i = 0; i < positions.size() - 1; ++i)
    {
        finalMessage += (positions[i].back());
    }
    return finalMessage;
}

int main()
{
    std::ifstream file("input5.txt");
    std::string firstLine;
    getline(file, firstLine); // init line
    file.clear();
    file.seekg(0);

    static std::vector<std::vector<char>> positions = initStateLoader(file, ((0.25 * firstLine.length()) + 0.25));

    std::cout << part2(file, positions);
}