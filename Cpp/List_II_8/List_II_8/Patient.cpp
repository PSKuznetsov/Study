//
//  Patient.cpp
//  List_II_8
//
//  Created by Paul Kuznetsov on 6/30/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include "Patient.hpp"

#pragma mark - Setters

void Patient::setFirstname(std::string name) {
    this->firstname = name;
}

void Patient::setLastname(std::string lastname) {
    this->lastname = lastname;
}

void Patient::setMiddlename(std::string middle) {
    this->middlename = middle;
}

void Patient::setGender(gender gen) {
    gen == male ? this->gndr = male : this->gndr = female;
}

#pragma mark - Getters

std::string Patient::getLastname() {
    
    return this->lastname;
}

std::string Patient::getFirstname() {
    
    return this->firstname;
}

std::string Patient::getMiddlename() {
    
    return this->middlename;
}

gender Patient::getGender() {
    
    return this->gndr;
}