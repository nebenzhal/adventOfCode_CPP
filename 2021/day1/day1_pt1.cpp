#include <iostream>
#include <fstream>

using namespace std;


int main(){
    string line = "0";
    string newLine;
    int largerCount = -1;

    ifstream infile ("inputs/input1.txt");

    while(getline(infile,newLine)){
        if((stoi(newLine))-(stoi(line)) > 0) largerCount++;
        line = newLine;
    }

    infile.close();
    cout << largerCount;
}