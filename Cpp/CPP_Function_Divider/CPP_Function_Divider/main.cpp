//
//  main.cpp
//  CPP_Function_Divider
//
//  Created by Paul Kuznetsov on 10/02/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


long findSumOfNumberDivider(long number) {
    long sum = 0;
    if (number == 1) {
        return 1;
    }
    for (int i = 2; i <= number/2; ++i) {
        if (number % i == 0) {
            sum+=i;
        }
    }
    
    return sum;
}

int main() {
    ifstream in ("/Users/NSCoder/Documents/C plus plus/CPP_Function_Divider/CPP_Function_Divider/input.txt");
    ofstream out ("/Users/NSCoder/Documents/C plus plus/CPP_Function_Divider/CPP_Function_Divider/output.txt");
    
    int leftEdge, rightEdge;
    int specialNumber;
    in >> leftEdge >> rightEdge;
    in >> specialNumber;
    
    for (int i = leftEdge; i <= rightEdge; ++i) {
        if (findSumOfNumberDivider(i) == specialNumber) {
            out << i << endl;
        }
    }
    
    return 0;
}
