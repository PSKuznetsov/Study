//
//  Student.cpp
//  sortStudentsUsingQSort
//
//  Created by Paul Kuznetsov on 28/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "Students.h"

#pragma mark - Setters

void Students::setFirstName(std::string fName) {
    this->firstName = fName;
}

void Students::setLastName(std::string lName) {
    this->lastName = lName;
}

void Students::setDayOfMonth(int day) {
    this->dayOfMonth = day;
}

void Students::setNumberOfMonth(int month) {
    this->numberOfMonth = month;
}

#pragma mark - Getters

std::string Students::getFirstName() {
    return this->firstName;
}

std::string Students::getLastName() {
    return this->lastName;
}

int Students::getDayOfMonth() {
    return this->dayOfMonth;
}

int Students::getNumberOfMonth() {
    return this->numberOfMonth;
}

#pragma mark - Operators

bool Students::operator > (Students b) {
    //For left operand
    int aDay = this -> getDayOfMonth();
    int aMonth = this -> getNumberOfMonth();
    //For right operand
    int bDay = b.getDayOfMonth();
    int bMonth = b.getNumberOfMonth();
    return (aMonth >= bMonth && aDay >= bDay);
}

bool Students::operator < (Students b) {
    //For left operand
    int aDay = this -> getDayOfMonth();
    int aMonth = this -> getNumberOfMonth();
    //For right operand
    int bDay = b.getDayOfMonth();
    int bMonth = b.getNumberOfMonth();
    return (aMonth <= bMonth && aDay <= bDay);
}