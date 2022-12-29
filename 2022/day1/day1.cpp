#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int tempNum = 0;
    int biggestNum = 0;
    string newLine;

    ifstream file ("test.txt");
    while(!file.eof()){

        int tempNum = 0;

        while((getline(file,newLine))){
            if (newLine.empty()) break;
            tempNum+=stoi(newLine);
        };
        
        if(tempNum> biggestNum) biggestNum=tempNum;

    };

    cout << biggestNum << "\n";
}