//
//  Software.cpp
//  cpp_class_II_10
//
//  Created by Paul Kuznetsov on 19/05/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//
#include <stdio.h>
#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"

class Software {
    
public:
    
    virtual void setSoftwareName(std::string) = 0;
    
    
};