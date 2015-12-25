//
//  FreeSoftware.cpp
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 04/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "FreeSoftware.h"

#pragma mark - Setters

 void FreeSoftware::setSoftwareName(std::string name) {
    
    this->softwareName = name;
}

void FreeSoftware::setDeveloperName(std::string developer) {
    
    this->developerName = developer;
}

#pragma mark - Getters

void FreeSoftware::showSoftwareName() {
    
    std::cout << "Free Software Name is: " << this->softwareName << std::endl;
}

void FreeSoftware::showDeveloperName() {
    
    std::cout << "Free Software developer is: " << this->developerName << std::endl;
}

#pragma mark - Constructors

FreeSoftware::FreeSoftware():softwareName(""),developerName("") {}