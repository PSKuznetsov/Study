//
//  String.cpp
//  class_solve_10
//
//  Created by Paul Kuznetsov on 07/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "newString.h"

#pragma mark - Setters
void newString::setLine(std::string lString) {
    this->line = lString;
}

#pragma mark - Getters
std::string newString::getLine() {
    return this->line;
}

#pragma mark - Constructures
newString::newString() {
    this->line = "";
}
newString::newString(std::string string) {
    this->line = string;
}

#pragma mark - Operators
newString newString::operator +(newString istring) {
    return this->line + istring.line;
}

bool newString::operator!() {
    return this->line.empty();
}

#pragma mark - Methods
void newString::printDigitsFromString() {
    std::string s = this->line;
    for (int i = 0; i < s.length(); ++i) {
        if (isdigit(s[i])) {
            std::cout << s[i] << " ";
        }
    }
}

void newString::printDigitsFromString(std::ofstream& outp) {
    std::string s = this->line;
    for (int i = 0; i < s.length(); ++i) {
        if (isdigit(s[i])) {
            outp << s[i] << " ";
        }
    }
}

unsigned long newString::sizeOfString() {
    return this->line.size();
}

void newString::printLargestSequence() {
    
    std::string s;
    char tmp;
    
    s = this->line;
    
    int max = 0;
    int count = 0;
    char sym = s[0];
    tmp = s[0];
    
    for (int i = 0; i < s.length(); ++i) {
        if (tmp == s[i]) {
            count++;
        }
        else {
            if (count > max) {
                max = count;
                sym = s[i];
            }
            
            count = 1;
            tmp = s[i];
        }
    }
    if (count > max) {
        max = count;
        sym = tmp;
    }
    std::cout << max << " " << sym;
}

void newString::printLargestSequence(std::ofstream& outp) {
    std::string s;
    char tmp;
    
    s = this->line;
    
    int max = 0;
    int count = 0;
    char sym = s[0];
    tmp = s[0];
    
    for (int i = 0; i < s.length(); ++i) {
        if (tmp == s[i]) {
            count++;
        }
        else {
            if (count > max) {
                max = count;
                sym = s[i];
            }
            
            count = 1;
            tmp = s[i];
        }
    }
    if (count > max) {
        max = count;
        sym = tmp;
    }
    outp << max << " " << sym;
}

