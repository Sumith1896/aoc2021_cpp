#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp; 
    inp.open("input.txt");

    string curr_cmd;
    double hor = 0;
    double ver = 0;
    double aim = 0;
    while (getline(inp, curr_cmd)) {
        stringstream ss(curr_cmd);
        string instruct, value;
        ss >> instruct;
        ss >> value;
        if (instruct == "forward") {
            hor += stoi(value);
            ver += aim * stoi(value);
        } else if (instruct == "down") {
            // ver += stoi(-alue);
            aim += stoi(value);
        } else {
            // ver -= stoi(value);
            aim -= stoi(value);
        }
    }
    
    cout << int(hor * ver) << endl;
    return 0;
}
