//
//  FreeSoftware.h
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 04/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "Software.cpp"

class FreeSoftware: public Software {

public:
    
    virtual void setSoftwareName(std::string);
    void setDeveloperName(std::string);
    
    void showSoftwareName();
    void showDeveloperName();
    
    FreeSoftware();
    
private:
    
    std::string softwareName;
    std::string developerName;
};