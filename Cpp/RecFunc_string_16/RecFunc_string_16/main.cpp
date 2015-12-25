//
//  main.cpp
//  RecFunc_string_16
//
//  Created by Paul Kuznetsov on 10/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream in ("/Users/NSCoder/Documents/C plus plus/RecFunc_string_16/RecFunc_string_16/input.txt");
ofstream out ("/Users/NSCoder/Documents/C plus plus/RecFunc_string_16/RecFunc_string_16/output.txt");

void fancyStringFromSymbol(char ansStr[], char str[], char symbol_a, char symbol_b, int index) {
    
    ansStr[index] = str[index];
    
    if(str[index] == symbol_a) {
        ansStr[index + 1] = symbol_b;
    }
    
    if(str[index] != '\0') {
        fancyStringFromSymbol(ansStr, str, symbol_a, symbol_b, ++index);
    }
}

int main() {
    
    char string[256];
    char ansString[256];
    char a;
    char b;
    
    in >> a >> b >> string;
    
    fancyStringFromSymbol(ansString, string, a, b, 0);
    
    out << ansString << " ";
    
    return 0;
}
