//
//  SharewareSoftware.h
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 04/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "FreeSoftware.h"

class SharewareSoftware: public Software {

private:
    
    std::string softwareName;
    std::string installationDate;
    std::string developerName;
    std::string expirationDate;
    
    bool isSoftwareExpired();

public:
    
    SharewareSoftware();
    
    virtual void setSoftwareName(std::string);
    void setInstalationDate(std::string);
    void setDeveloperName(std::string);
    
    void showSoftwareName();
    void showInstalationDate();
    void showDeveloperName();
    void showExpirationDate();
};