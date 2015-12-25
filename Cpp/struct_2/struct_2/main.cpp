//
//  main.cpp
//  struct_2
//
//  Created by Paul Kuznetsov on 25/11/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream in("/Users/NSCoder/Library/Developer/Xcode/DerivedData/struct_2-bnmjbfirbifzazdkpsxtpenvsajd/Build/Products/Debug/input.txt");
ofstream out("output.txt");

struct Student {
    string firstName;
    string middleName;
    string lastName;
    int    dateOfBirthday;
    string adress;
    string school;
    void   printInfo();
    void   readInfo();
};

void Student::readInfo() {
    in >> firstName;
    in >> middleName;
    in >> lastName;
    in >> dateOfBirthday;
    in >> adress;
    in >> school;
    
}

void Student::printInfo() {
    out << firstName << " " << middleName << " " << lastName << endl;
    out << dateOfBirthday << endl << adress << endl << school << endl;
}

int main() {
    Student person[30];
    for (int i = 0; i < 30; i++) {
        person[i].readInfo();
    }
    
    for (int i = 0; i < 30; i++) {
        if (!person[i].school.compare("TTT")) {
            person[i].printInfo();
        }
    }
    
    
    return 0;
}
