//
//  main.cpp
//  CPPSortUsingComparator
//
//  Created by Paul Kuznetsov on 07/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

bool sortStudentStructUsingComparator(Student a, Student b) {
    //For student "A"
    int aDay   = a.Student::getDayOfMonth();
    int aMonth = a.Student::getNumberOfMonth();
    //For student "B"
    int bDay   = b.Student::getDayOfMonth();
    int bMonth = b.Student::getNumberOfMonth();
    
    return (aMonth < bMonth && aDay <= bDay);
}

int main() {
    
    ifstream in ("/Users/NSCoder/Documents/Xcode/C++/CPPSortUsingComparator/CPPSortUsingComparator/input.txt");
    ofstream out("/Users/NSCoder/Documents/Xcode/C++/CPPSortUsingComparator/CPPSortUsingComparator/output.txt");
    
    vector<Student>vectorOfStudents;
    int n;
    Student tmp;
    string str_tmp;
    int int_tmp;
    in >> n;
    
    for (int i = 0; i < n; ++i) {
        in >> str_tmp;
        tmp.setFirstName(str_tmp);
        in >> str_tmp;
        tmp.setLastName(str_tmp);
        in >> int_tmp;
        tmp.setDayOfMonth(int_tmp);
        in >> int_tmp;
        tmp.setNumberOfMonth(int_tmp);
        vectorOfStudents.push_back(tmp);
    }
    
   sort(vectorOfStudents.begin(), vectorOfStudents.end(), sortStudentStructUsingComparator);
    
    for (int i = 0; i < vectorOfStudents.size(); ++i) {
        out << vectorOfStudents[i].getFirstName() << " " << vectorOfStudents[i].getLastName() << " " << vectorOfStudents[i].getDayOfMonth() << "/" << vectorOfStudents[i].getNumberOfMonth() << endl;
    }
    
    return 0;
}
