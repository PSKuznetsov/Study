//
//  main.cpp
//  PK_2_1_3_5
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

    string mainString;
    string fChar;
    getline(in,mainString);



    string::size_type pos = 0, val = 0;
    int count = 0;
    val = mainString.find(" ", pos);

    out << "Answer is: ";

    if (!mainString.empty()) {
        while (val != string::npos) {
            count++;
            pos = val + 1;
            val = mainString.find(" ", pos);
        }
        out << count + 1 << endl;
    }
    else out << 0 << endl;
    return 0;
}