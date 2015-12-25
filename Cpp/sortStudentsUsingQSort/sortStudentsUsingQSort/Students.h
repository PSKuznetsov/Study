//
//  Student.h
//  sortStudentsUsingQSort
//
//  Created by Paul Kuznetsov on 28/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <stdio.h>
#include <string>
class Students {
private:
    std::string firstName;
    std::string lastName;
    
    int dayOfMonth;
    int numberOfMonth;
    
public:
    //Setters
    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setDayOfMonth(int day);
    void setNumberOfMonth(int month);
    //Getters
    std::string getFirstName();
    std::string getLastName();
    int getDayOfMonth();
    int getNumberOfMonth();
    //Operators
    bool operator > (Students);
    bool operator < (Students);
};