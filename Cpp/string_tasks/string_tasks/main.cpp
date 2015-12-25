//
//  main.cpp
//  string_tasks
//
//  Created by Paul Kuznetsov on 01/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

//
//
//Strings pt. II solves: 5, 6;
//
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream in ("/Users/NSCoder/Documents/C++ projects/string_tasks/string_tasks/input.txt");
    ofstream out ("/Users/NSCoder/Documents/C++ projects/string_tasks/string_tasks/output.txt");
    
    string mainStr;
    string fChar;
    
    
    //II - 5
    in >> mainStr >> fChar;
    string::size_type k = 0, t = 0, pos = 0, endPos = 0;
    k = mainStr.find(fChar, pos);
    while (k != string::npos) {
        mainStr.insert(k + 1, fChar);
        pos = k + 2;
        k = mainStr.find(fChar, pos);
    }
    out << mainStr << endl;
    
    
    //II - 6
    in >> mainStr >> fChar;
    pos = 0, k = 0;
    k = mainStr.find(fChar, pos);
    while (k != string::npos) {
        mainStr.erase(k, 1);
        pos = k + 1;
        k = mainStr.find(fChar, pos);
    }
    out << mainStr << endl;
    
    
    //II - 17

    getline(in, fChar);
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
    
    in.close();
    out.close();
    return 0;
}
