//
//  main.cpp
//  List_II_8
//
//  Created by Paul Kuznetsov on 6/30/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <utility>
#include <fstream>
#include "Patients.hpp"

using namespace std;



#pragma mark - Main

int main() {
    
    ifstream in ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/List_II_8/List_II_8/input.txt");
    ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/List_II_8/List_II_8/output.txt");
   
    Patients* patients = new Patients;
    
    Patient* cur = new Patient;
    
    int n;
    string line;
    
    in >> n;
    
    for (int i = 0; i < n; ++i) {
        
        in >> line;
        cur->setFirstname(line);
        
        in >> line;
        cur->setMiddlename(line);
        
        in >> line;
        cur->setLastname(line);
        
        in >> line;
        line == "male" ? cur->setGender(male) : cur->setGender(female);
        
        patients->addPatientToTail(cur);
    }
    
    patients->movePatientToFront(cur);
    
    patients->replaceBackPatientWithPatient(cur);
    
    pair<double, double> calc = patients->calcPercentage();
    
    patients->printToFile(out);
    
    out << "Male percentage: " << calc.first << " female percentage: " << calc.second << endl;
    
    return 0;
}
