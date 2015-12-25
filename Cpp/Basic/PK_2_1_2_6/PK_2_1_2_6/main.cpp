//
//  main.cpp
//  PK_2_1_2_6
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
    string::size_type k = 0, t = 0, pos = 0;
    in >> mainStr >> fChar;
    pos = 0, k = 0;
    k = mainStr.find(fChar, pos);
    while (k != string::npos) {
        mainStr.erase(k, 1);
        pos = k + 1;
        k = mainStr.find(fChar, pos);
    }
    out << mainStr << endl;

    return 0;
}