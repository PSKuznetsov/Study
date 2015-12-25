//
//  SharewareSoftware.cpp
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 04/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "SharewareSoftware.h"

#pragma mark - Setters

void SharewareSoftware::setSoftwareName(std::string name) {
    
    this->softwareName = name;
}

void SharewareSoftware::setDeveloperName(std::string developer) {
    
    this->developerName = developer;
}

void SharewareSoftware::setInstalationDate(std::string date) {
    
    this->installationDate = date;
}

#pragma mark - Getters

void SharewareSoftware::showSoftwareName() {
    
    std::cout << "Shareware Software Name is: " << this->softwareName << std::endl;
}

void SharewareSoftware::showExpirationDate() {
    
    bool result = this->isSoftwareExpired();
    
    std::cout << "Shareware Software expired: " << (result ? "Yes" : "No") << std::endl;
}

void SharewareSoftware::showDeveloperName() {
    
    std::cout << "Shareware Software developer is: " << this->developerName << std::endl;
}

void SharewareSoftware::showInstalationDate() {
    
}

#pragma mark - Constructors

SharewareSoftware::SharewareSoftware():installationDate("1970/1/1") {}

#pragma mark - Logic Methods

bool SharewareSoftware::isSoftwareExpired() {
    
    boost::gregorian::date instDate = boost::gregorian::from_simple_string(this->installationDate);
    boost::gregorian::date expDate  = instDate + boost::gregorian::months(1);
    
    this->expirationDate = boost::gregorian::to_simple_string(expDate);
    
    boost::gregorian::date nowDate  = boost::gregorian::day_clock::local_day();
    
    return nowDate > expDate;
}


