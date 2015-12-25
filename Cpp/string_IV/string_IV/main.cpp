//
//  main.cpp
//  string_IV
//
//  Created by Paul Kuznetsov on 06/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//
// IV solves: 5, 6
//

int main() {
    ifstream in("/Users/NSCoder/Documents/C++ projects/string_IV/string_IV/input.txt");
    ofstream out("/Users/NSCoder/Documents/C++ projects/string_IV/string_IV/output.txt");
#pragma mark - IV solve 5
    out << "----------------------------------------------------" << endl;
    out << "IV solve 5" << endl << endl;
    
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
    out << "----------------------------------------------------" << endl;
    
    in.close();
    out.close();
    return 0;
}
