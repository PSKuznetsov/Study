//
//  main.cpp
//  PK_2_1_2_5
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    string mainStr;
    string fChar;

    in >> mainStr >> fChar;
    string::size_type k = 0, t = 0, pos = 0;
    k = mainStr.find(fChar, pos);
    while (k != string::npos) {
        mainStr.insert(k + 1, fChar);
        pos = k + 2;
        k = mainStr.find(fChar, pos);
    }
    out << mainStr << endl;
    return 0;
}