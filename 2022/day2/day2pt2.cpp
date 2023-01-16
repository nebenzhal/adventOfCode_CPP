#include <iostream>
#include <fstream>
#include <map>

int pickWinner(char &enemyPick, const std::map<char, int> &choices)
{
    int myPickPosition = choices.at(enemyPick) + 1;
    return (myPickPosition % 3 + !((myPickPosition) % 3) * 3);
}
int pickLooser(char &enemyPick, const std::map<char, int> &choices)
{
    int myPickPosition = choices.at(enemyPick) + 2;
    return myPickPosition % 3 + !((myPickPosition) % 3) * 3;
}

int main()
{
    std::ifstream file("input2.txt");
    std::string newLine;
    int totalScore = 0;

    // this works on the assumption that the order of rock paper scissors is the same as the score each are given

    const std::map<char, int> choices = {
        {'A', 1}, // rock
        {'B', 2}, // paper
        {'C', 3}  // scissors
    };

    while (!file.eof())
    {
        while (getline(file, newLine))
        {
            char enemyPick = newLine[0];
            char myPick = newLine[2];
            if (myPick == 'Z')
                totalScore += pickWinner(enemyPick, choices) + 6;
            else if (myPick == 'Y')
                totalScore += choices.at(enemyPick) + 3;
            else
                totalScore += pickLooser(enemyPick, choices);
        }
    }
    std::cout << "\nthe total score is: " << totalScore << '\n';
};
