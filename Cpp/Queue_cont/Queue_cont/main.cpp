//
//  main.cpp
//  Queue_cont
//
//  Created by Paul Kuznetsov on 6/29/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

struct Student {
    
    string firstname;
    string lastname;
    string middlename;
    
    string gender;
    int age;
    int salary;
};

int main() {
    
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    
    int n;
    Student temp;
    queue<Student> qUnderThirty;
    queue<Student> qAboveThirty;
    
    in >> n;
    
    for (int i = 0; i < n; ++i) {
        
        in >> temp.lastname;
        in >> temp.firstname;
        in >> temp.middlename;
        in >> temp.gender;
        in >> temp.age;
        in >> temp.salary;
        
        temp.age < 30 ? qUnderThirty.push(temp) : qAboveThirty.push(temp);
    }
    
    while (!qUnderThirty.empty()) {
        
        temp = qUnderThirty.front();
        qUnderThirty.pop();
        
        out << temp.lastname << " " << temp.firstname << " " << temp.middlename << " " << temp.gender << " " << temp.age << " " << temp.salary << endl;
    }
    
    while (!qAboveThirty.empty()) {
        
        temp = qAboveThirty.front();
        qAboveThirty.pop();
        
        out << temp.lastname << " " << temp.firstname << " " << temp.middlename << " " << temp.gender << " " << temp.age << " " << temp.salary << endl;
    }
    
    return 0;
}
