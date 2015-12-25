//
//  main.cpp
//  OverideFunc_10
//
//  Created by Paul Kuznetsov on 03/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "overideF.h"

using namespace std;

int main() {
    ifstream in ("/Users/NSCoder/Documents/C plus plus/OverideFunc_10/OverideFunc_10/input.txt");
    ofstream out("/Users/NSCoder/Documents/C plus plus/OverideFunc_10/OverideFunc_10/output.txt");
    
    double x, y;
    
    in >> x;
    
    y = getResultOfFunc(x);
    
    out << "Answer #1: " << y << endl;
    
    getResultOfFunc(x, y);
    
    out << "Answer #2: " << y << endl;
    
    
    return 0;
}
