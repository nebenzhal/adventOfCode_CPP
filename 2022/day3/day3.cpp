#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("input3.txt");
    std::string newLine;
    int i = 0;
    int priority = 0;

    while (!file.eof())
    {
        while (getline(file, newLine))
        {
            std::string firstHalf = newLine.substr(0, newLine.length()/2);
            std::string secondhalf = newLine.substr(newLine.length()/2, newLine.length());

            for (char c : firstHalf)
            {
                ++i;
                auto r = find(secondhalf.begin(), secondhalf.end(), c);
                if (r != secondhalf.end())
                {
                    priority += (c-'0'-48) + ((c-'0'-48) <= 0 ? 58 : 0);
                    break;
                    
                }
            };

        }
    }
    std::cout << priority << '\n';

}

// int priorityGetter(char &duplicateChar)
// {
//     int priority = duplicateChar - '0' - 48;

// };