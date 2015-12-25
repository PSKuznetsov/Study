//
//  Patients.hpp
//  List_II_8
//
//  Created by Paul Kuznetsov on 7/3/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <stdio.h>
#include <list>
#include <utility>
#include <fstream>
#include "Patient.hpp"

class Patients {
private:
    std::list<Patient> patientsList;
    
    int male_count;
    int female_count;

public:
    
    Patients();
    //Patients(int size);
    ~Patients();
    
    void addPatientToTail(Patient* patient);
    void replaceBackPatientWithPatient(Patient* patient);
    void movePatientToFront(Patient* patient);
    void printToFile(std::ofstream& out);
    std::pair<double, double> calcPercentage();
};