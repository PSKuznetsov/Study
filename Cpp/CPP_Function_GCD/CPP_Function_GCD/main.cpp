//
//  main.cpp
//  CPP_Function_GCD
//
//  Created by Paul Kuznetsov on 10/02/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

long findGCD(long n, long m) {
    while (m) {
        n %= m;
        swap(n, m);
    }
    return n;
}

int main() {
    ifstream in("/Users/NSCoder/Documents/C plus plus/CPP_Function_GCD/CPP_Function_GCD/input.txt");
    ofstream out("/Users/NSCoder/Documents/C plus plus/CPP_Function_GCD/CPP_Function_GCD/output.txt");
    int n, m;
    in >> n >> m;
    out << "LCM is: " << (n * m)/findGCD(n, m);
    return 0;
}
