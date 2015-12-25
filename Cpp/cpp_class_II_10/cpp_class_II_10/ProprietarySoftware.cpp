//
//  ProprietarySoftware.cpp
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 04/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "ProprietarySoftware.h"

#pragma mark - Setters

/*void ProprietarySoftware::setCurrentDate(std::string date) {
    
    this->currentDate = date;
}*/

void ProprietarySoftware::setSoftwareName(std::string name) {
    
    this->softwareName = name;
}

void ProprietarySoftware::setInstalationDate(std::string date) {
    
    this->installationDate = date;
}

void ProprietarySoftware::setDeveloperName(std::string developer) {
    
    this->developerName = developer;
}

void ProprietarySoftware::setSoftwarePrice(double price) {
    
    this->softwarePrice = price;
}

#pragma mark - Getters

void ProprietarySoftware::showSoftwareName() {
    
    std::cout << "Proprietary Software Name is: " << this->softwareName << std::endl;
}

void ProprietarySoftware::showInstalationDate() {
    
    std::cout << "Proprietary Software installation date is: " << this->installationDate << std::endl;
}

void ProprietarySoftware::showSoftwarePrice() {
    
    std::cout << "Proprietary Software price is: " << this->softwarePrice << std::endl;
}

void ProprietarySoftware::showDeveloperName() {
    
    std::cout << "Proprietary Software developer is: " << this->developerName << std::endl;
}

void ProprietarySoftware::showUsageTimeDate() {
    
    this->calculateUsageTime();
    std::cout << "Proprietary Software usage period is: " << this->usageTime << std::endl;
}

#pragma mark - Constructors

ProprietarySoftware::ProprietarySoftware():currentDate("1970/1/1"),installationDate("1970/1/1"){}

#pragma mark - Logic Methods

void ProprietarySoftware::calculateUsageTime() {
    
    boost::gregorian::date instDate = boost::gregorian::from_simple_string(this->installationDate);
    boost::gregorian::date nowDate  = boost::gregorian::day_clock::local_day();
    
    this->currentDate = boost::gregorian::to_simple_string(nowDate);
    
    boost::gregorian::date_period timeOfUse(instDate, nowDate);
    
    this->usageTime = boost::gregorian::to_simple_string(timeOfUse);
    
}









