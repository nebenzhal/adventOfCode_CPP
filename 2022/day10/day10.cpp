#include <tuple>
#include "tuple"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// should i operate while disk reading, or read from disk to ram then operate?

int part1(std::vector<std::string> instructions)
{
    int cycle = 0;
    int X = 1;
    std::vector<std::tuple<int, int>> xChanges;
    for (const std::string &line : instructions)
    {
        switch (line[0])
        {
        case ('n'):
            cycle++;
            if ((cycle - 20) % 40 == 0)
                xChanges.push_back(std::make_tuple(cycle, X));
            continue;

        case ('a'):
            for (int i = 0; i < 2; i++)
            {
                cycle++;
                if ((cycle - 20) % 40 == 0)
                    xChanges.push_back(std::make_tuple(cycle, X));
                X += stoi(line.substr(line.find(' '), line.length())) * i; // if on first cycle, i=0 and nothing is added.
                continue;
            }
        }
    }

    int finalScore = 0;
    for (const auto &x : xChanges)
    {
        finalScore += std::get<0>(x) * std::get<1>(x);
    }
    return finalScore;
}

int main()
{
    std::fstream input("input10.txt");

    std::string tmpLine;
    std::vector<std::string> instructions;
    while (getline(input, tmpLine))
    {
        instructions.push_back(tmpLine);
    }
    std::cout<<part1(instructions)<<'\n';
}
