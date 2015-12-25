//
//  String.h
//  class_solve_10
//
//  Created by Paul Kuznetsov on 07/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

class newString {

private:
    std::string line;

public:
    void setLine(std::string);
    std::string getLine();
   
    newString();
    newString(std::string);
    
    newString operator + (newString);
    bool operator ! ();
    
    void printDigitsFromString();
    void printDigitsFromString(std::ofstream& outp);
    
    unsigned long sizeOfString();
    
    void printLargestSequence();
    void printLargestSequence(std::ofstream& outp);
};