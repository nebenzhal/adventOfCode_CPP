#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> parser(std::string &substr)
{
    std::vector<int> list;
    list.push_back(stoi(substr.substr(0, substr.find('-'))));
    list.push_back(stoi(substr.substr(substr.find('-') + 1, substr.find(',') - 2)));
    list.push_back(stoi(substr.substr(substr.find(',') + 1, substr.find_last_of('-'))));
    list.push_back(stoi(substr.substr(substr.find_last_of('-') + 1, substr.length())));

    return list;
}

int part1(std::ifstream &file)
{
    int score = 0;
    std::string singleElf;

    while (getline(file, singleElf))
    {
        std::vector<int> list = parser(singleElf);
        if (list[0] <= list[2] && list[3] <= list[1] || list[2] <= list[0] && list[1] <= list[3])
            ++score; // i don't know why part2 won't work, i checked other solution and they did it just like me but in python and it worked, welp :/
    }
    return score;
}

int part2(std::ifstream &file)
{
    int score = 0;
    std::string singleElf;

    while (getline(file, singleElf))
    {
        std::vector<int> list = parser(singleElf);

        if ((list[0] <= list[2] <= list[1]) xor (list[2] <= list[0] <= list[3]))
            std::cout << "true\n";

        std::cout << list[0] << " : " << list[2] << " : " << list[1] << " ||| " << list[2] << " : " << list[0] << " : " << list[3] << '\n';
    }
}

int main()
{
    std::ifstream file{"test4.txt"};
    // std::cout <<"part 1: " <<part1(file) << '\n';
    std::cout << "part 2: " << part2(file) << '\n';
};

// list[0] min1
//  list[1] max1
// list[2] min2
//  list[3] max2

// max1 >= min2 >= min1
// min1 <= min2 <= max1