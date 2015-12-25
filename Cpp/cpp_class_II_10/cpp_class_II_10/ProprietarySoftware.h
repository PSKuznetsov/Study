//
//  ProprietarySoftware.h
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 04/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "SharewareSoftware.h"

class ProprietarySoftware: public Software {
private:
    
    std::string softwareName;
    std::string currentDate;
    std::string installationDate;
    std::string developerName;
    std::string usageTime;
    double softwarePrice;
    
    void calculateUsageTime();
    
public:
    
    ProprietarySoftware();
    
    virtual void setSoftwareName(std::string);
    //void setCurrentDate(std::string); //deprecated
    void setInstalationDate(std::string);
    void setDeveloperName(std::string);
    void setSoftwarePrice(double price);
    
    void showSoftwareName();
    void showUsageTimeDate();
    void showInstalationDate();
    void showDeveloperName();
    void showSoftwarePrice();
};