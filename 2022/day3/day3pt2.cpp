#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file{"input3.txt"};

    std::string line;
    std::string line2;
    std::string line3;
    int i = 0;
    int priority = 0;
    std::string megaLine = "";


        while (!file.eof() && file >> line >> line2 >> line3)
        {
            for(char c:line){

            auto r = find(line2.begin(), line2.end(), c);
            auto r2 = find(line3.begin(), line3.end(), c);

            if(r != line2.end() && r2!=line3.end()){
                priority += (c-'0'-48) + ((c-'0'-48) <= 0 ? 58 : 0);
                break;
            }

            }

        };
        std::cout << priority;
}
