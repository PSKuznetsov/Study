//
//  Patient.hpp
//  List_II_8
//
//  Created by Paul Kuznetsov on 6/30/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <stdio.h>
#include <string>

enum gender {
    male,
    female
};

class Patient {
    
private:
    
    std::string firstname;
    std::string lastname;
    std::string middlename;
    
    gender gndr;
    
public:
    
    void setFirstname(std::string);
    void setLastname(std::string);
    void setMiddlename(std::string);
    void setGender(gender);
    
    std::string getLastname();
    std::string getFirstname();
    std::string getMiddlename();
    gender getGender();
    
};