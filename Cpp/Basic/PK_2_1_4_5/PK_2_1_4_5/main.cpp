#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string::size_type pos = 0, val = 0;
    int max = INT32_MIN;
    int tmpVal = 0;
    string fChar, mainString;

    getline(in, mainString);
    val = mainString.find(" ", pos);

    if (val != string::npos) {
        while (val != string::npos) {
            fChar = mainString.substr(pos, val);
            if (isdigit(*fChar.c_str())) {
                tmpVal = stoi(fChar);
                if (tmpVal > max) {
                    max = tmpVal;
                }
            }
            pos = val + 1;
            val = mainString.find(" ", pos);
        }
        fChar = mainString.substr(mainString.length() - mainString.rfind(" "));
        if (!fChar.empty()) {
            if (isdigit(*fChar.c_str())) {
                tmpVal = stoi(fChar);
                if (tmpVal > max) {
                    max = tmpVal;
                }
            }
        }
        else {
            if (isdigit(*mainString.c_str())) {
                tmpVal = stoi(mainString);
                if (tmpVal > max) {
                    max = tmpVal;
                }
            }
        }
    }
    else {
        if (isdigit(*mainString.c_str())) {
            tmpVal = stoi(mainString);
            if (tmpVal > max) {
                max = tmpVal;
            }
        }
    }

    out << "Answer is: " << max << endl;

    in.close();
    out.close();
    return 0;
}