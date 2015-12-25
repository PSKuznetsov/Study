//
//  main.cpp
//  class_solve_10
//
//  Created by Paul Kuznetsov on 07/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "newString.h"

using namespace std;

int main() {
    
    ifstream in ("/Users/NSCoder/Documents/Xcode/C++/class_solve_10/class_solve_10/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Xcode/C++/class_solve_10/class_solve_10/output.txt");
   
    //initialization
    newString str = newString("ab67ba");
    newString str2 = newString();
    str2.setLine("bbbb");
    
    //Operators test
    out << "String is empty: " << (!str ? "YES" : "NO") << "\n";
    str = str + str2;
    out << "Summ of strings: " << str.getLine() << "\n";
    
    ;
    
    //Testing Methods
    out << "\nDigits from string: ";
    str.printDigitsFromString(out);
    out << "\nSize of string: " << str.sizeOfString() << "\nThe Lagest Sequence: ";
    str.printLargestSequence(out);
    
    return 0;
}
