//
//  Patients.cpp
//  List_II_8
//
//  Created by Paul Kuznetsov on 7/3/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include "Patients.hpp"

#pragma mark - Constructors

Patients::Patients() {}

Patients::~Patients() {
    
    this->patientsList.~list();
}

#pragma mark - Actions methods

void Patients::printToFile(std::ofstream& out) {
    
    for (auto it = this->patientsList.begin(); it != this->patientsList.end(); it++) {
        
        auto cur = &*it;
        
        out << cur->getFirstname() << " ";
        out << cur->getMiddlename() << " ";
        out << cur->getLastname() << " ";
        out << std::endl;
    }
}

void Patients::addPatientToTail(Patient* patient) {
    
    this->patientsList.push_back(*patient);
    patient->getGender() == male ? male_count++ : female_count++;
}

void Patients::replaceBackPatientWithPatient(Patient* patient) {
    
    for (auto i = patientsList.begin(), j = patientsList.end(); i != j; i++) {
        
        Patient cur = *i;
        
        if (cur.getFirstname() == patient->getFirstname()) {
            
            Patient back = patientsList.back();
            
            auto it = i;
            it++;
            
            patientsList.insert(it, back);
            patientsList.erase(i);
            
            patientsList.pop_back();
            patientsList.push_back(cur);
            return;
        }
        
    }

}

void Patients::movePatientToFront(Patient* patient) {
    
    for (auto it = patientsList.begin(); it != patientsList.end(); it++) {
        
        Patient *cur = new Patient;
        
        cur = &*it;
        
        if (cur->getFirstname() == patient->getFirstname()) {
            
            this->patientsList.push_front(*cur);
            this->patientsList.erase(it);
            
        }
    }
    
}

std::pair<double, double> Patients::calcPercentage() {
    
    int overall = this->male_count + this->female_count;
    
    double male_perc = ((double)male_count/overall) * 100;
    double female_perc = ((double)female_count/overall) * 100;
    
    return std::pair<double, double>(male_perc, female_perc);
}
