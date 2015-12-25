//
//  main.cpp
//  string_solve_III
//
//  Created by Paul Kuznetsov on 01/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

//
//
//  Strings III solves:5, 6, 17
//
//

struct Phrase {
    string word;
    bool marker = false;
};

int main() {
    ifstream in ("/Users/NSCoder/Documents/C++ projects/string_solve_III/string_solve_III/input.txt");
    ofstream out ("/Users/NSCoder/Documents/C++ projects/string_solve_III/string_solve_III/output.txt");
    
    //
    // III solve: 5
    //
    
#pragma mark - III solve 5
    
    out << "III solve: 5" << endl << endl;
    
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
    out << "------------------------------------------" << endl;
    
    //
    // III solve: 6
    //
    
#pragma mark - III solve 6
    
    out << "III solve 6" << endl << endl;
    
    getline(in, fChar);
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
    out << "------------------------------------------" << endl;
    
    //
    // III solve: 11
    //
    
#pragma mark - III solve 11
    
    out << "III solve 11" << endl << endl;
    
    
    unsigned int number;
    int amountOfValues = 1;
    in >> number;
    
    Phrase* phraseArray = new Phrase();
    int index = 0;
    
    while (!in.eof()) {
        in >> phraseArray[index].word;
        index++;
    }
    
    for (int i = 0; i < index - 1; i ++) {
        phraseArray[i].marker = true;
        for (int j = i + 1; j < index; j++) {
            if (phraseArray[i].word == phraseArray[j].word && phraseArray[j].marker != true) {
                amountOfValues++;
                phraseArray[j].marker = true;
            }
        }
        if (amountOfValues > number) {
            out << "Word: " <<phraseArray[i].word << " met in phrase " << amountOfValues << " times" << endl;
            amountOfValues = 1;
        }
    }
    out << endl;
    out << "------------------------------------------" << endl;
    
    in.close();
    out.close();
    return 0;
}
