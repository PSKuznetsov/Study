//
//  main.cpp
//  PK_1_1_3_10
//
//  Created by Paul Kuznetsov on 21/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in ("input.txt");
    ofstream out("output.txt");
    int number;
    in >> number;
    out << "Sum of digit is even: " << ((number % 10 + ((number / 10) % 10)) % 2 == 0 ? "Yes" : "No") << endl;
    in.close();
    out.close();
    return 0;
}