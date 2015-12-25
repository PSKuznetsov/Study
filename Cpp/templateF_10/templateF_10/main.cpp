//
//  main.cpp
//  templateF_10
//
//  Created by Paul Kuznetsov on 03/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "arrayF.h"

using namespace std;

int main() {
    
    ifstream in ("/Users/NSCoder/Documents/C plus plus/templateF_10/templateF_10/input.txt");
    ofstream out("/Users/NSCoder/Documents/C plus plus/templateF_10/templateF_10/output.txt");
    
    int** array = createArray<int*, int>(10, 10);
    
    return 0;
}
