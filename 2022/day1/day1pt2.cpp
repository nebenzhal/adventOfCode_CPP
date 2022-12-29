#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    int tempNum = 0;
    vector<int> calorieSums;
    string newLine;

    ifstream file ("input1.txt");
    while(!file.eof()){

        int tempNum = 0;

        while((getline(file,newLine))){
            if (newLine.empty()) break;
            tempNum+=stoi(newLine);
        };
        
        calorieSums.push_back(tempNum);

    };

    sort(calorieSums.begin(),calorieSums.end());
    const int len = calorieSums.size();
    cout << calorieSums[len-1]+calorieSums[len-2]+calorieSums[len-3] << '\n';

}