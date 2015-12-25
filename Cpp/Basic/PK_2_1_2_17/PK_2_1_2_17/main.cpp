//
//  main.cpp
//  PK_2_1_2_17
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

    string mainStr;
    string fChar;

    string::size_type k = 0, t = 0, pos = 0, endPos = 0;

    getline(in, mainStr);
    pos = 0, k = 0;
    endPos = mainStr.length();
    k = mainStr.find(" ", pos);
    t = mainStr.rfind(" ", endPos);

    if (t == k) {
        out << " " << endl;
    }
    else {
        fChar = mainStr.substr(k + 1, t - k);
        out << fChar << endl;
    }
    return 0;
}