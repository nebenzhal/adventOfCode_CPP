#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int command_interpreter(const std::string &line)
{
    if (line[0] == '$' && line[3] == 's') //1=ls
        return 1;
    else if (line[0] == '$')
        return (line[5] == '.' ? 3 : 2); //2=cd 3=cd..
    else
        return 0; // info lines, feed into sizeNumParser
};

void sizeNumParser(std::unordered_map<std::string, long> &dirs, const std::string &line, const std::vector<std::string> &currentPath)
{
    std::string currentFullPath;
    long fileSize = stoi(line.substr(0, ' '));
    for (std::string singularPath : currentPath) currentFullPath += (singularPath);
    for (int i = 0; i < currentPath.size(); ++i) dirs[((currentPath[i-1])+(currentPath[i]))] += fileSize;
};

int part2(std::unordered_map<std::string, long> &dirs){
    int neededSpace = 30000000-(70000000-dirs["/"]);
    std::vector<int> dirSizes;
    dirSizes.reserve(dirs.size());

    for (auto val:dirs) if ((val.second>=neededSpace)) dirSizes.push_back(val.second);
    std::sort(dirSizes.begin(),dirSizes.end());
    return dirSizes[0];
}

int part1(std::unordered_map<std::string, long> &dirs){
    long total = 0;
    for (const auto &x : dirs) if (x.second < 100000) total += x.second;
    return total;
}

int main()
{
    std::ifstream input("input7.txt");
    static std::unordered_map<std::string, long> dirs;
    std::vector<std::string> currentPath;

    std::string line;
    while (!input.eof())
    {
        while (getline(input, line))
        {
            switch (command_interpreter(line))
            {
            case 0:
                if (isdigit(line[0]))
                    sizeNumParser(dirs, line, currentPath);
                else
                    continue;
            case 1: // ls
                // loop and feed lines to sizeNumParser until the next command is detected, beginning from the line after ls
                continue;
            case 2: //cd
            {
                std::string dirName = (line.substr(5, line.length()));
                currentPath.push_back(dirName);
                continue;
            }
            case 3: // cd ..
                currentPath.pop_back();
                continue;
            }
        }
    }
    std::cout << part2(dirs) << '\n';

}