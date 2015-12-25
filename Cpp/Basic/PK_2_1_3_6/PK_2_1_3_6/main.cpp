//
//  main.cpp
//  PK_2_1_3_6
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ifstream in ("input.txt");
    ofstream out ("output.txt");
    string::size_type pos = 0, val = 0;
    int count = 0;
    string mainString;
    string fChar;
    getline(in, mainString);
    unsigned int dataLength;

    out << "Answer is: ";

    in >> dataLength;
    count = 0;
    pos   = 0;
    val   = 0;
    val   = mainString.find(" ", pos);

    if (!mainString.empty()) {
        while (val != string::npos) {
            fChar = mainString.substr(pos, val - pos);
            if (fChar.length() == dataLength) {
                count++;
                out << fChar << " ";
            }
            pos = val + 1;
            val = mainString.find(" ", pos);
        }
        if (mainString.length() - mainString.rfind(" ") - 1 == dataLength) {
            count++;
            fChar = mainString.substr(mainString.rfind(" ") + 1, mainString.length());
            out << fChar;
        }
        out << endl << "Amount of values: " << count << endl;
    }
    else {
        out << 0 << endl;
    }
    return 0;
}