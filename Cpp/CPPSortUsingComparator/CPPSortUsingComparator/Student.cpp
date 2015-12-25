//
//  Student.cpp
//  CPPSortUsingComparator
//
//  Created by Paul Kuznetsov on 07/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "Student.h"

#pragma mark - Setters

void Student::setFirstName(std::string fName) {
    this->firstName = fName;
}

void Student::setLastName(std::string lName) {
    this->lastName = lName;
}

void Student::setDayOfMonth(int day) {
    this->dayOfMonth = day;
}

void Student::setNumberOfMonth(int month) {
    this->numberOfMonth = month;
}

#pragma mark - Getters

std::string Student::getFirstName() {
    return this->firstName;
}

std::string Student::getLastName() {
    return this->lastName;
}

int Student::getDayOfMonth() {
    return this->dayOfMonth;
}

int Student::getNumberOfMonth() {
    return this->numberOfMonth;
}