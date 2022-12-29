#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(){
    ifstream file ("input2.txt");
    string newLine;
    int totalScore = 0;

    const map<char,char> choices = {
        {'X','1'},
        {'Y','2'},
        {'Z','3'}
    };

    const map<char,char> loses = {
        {'A','Z'},
        {'B','X'},
        {'C','Y'}
    };

    while(!file.eof()){
        while(getline(file,newLine)){
            totalScore+=(choices.at(newLine[2]))-'0';
            if(((choices.at(newLine[2]))-'0')==(int(newLine[0])-'0'-16))  totalScore+=3; //If its a tie
            else if (newLine[2] == loses.at(newLine[0])) break;
            else totalScore+=6;
        }
    }
    cout << totalScore << '\n';
};
