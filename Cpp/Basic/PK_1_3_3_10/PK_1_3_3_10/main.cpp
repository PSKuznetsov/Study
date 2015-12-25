//
//  main.cpp
//  PK_1_3_3_10
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_3_3_10/PK_1_3_3_10/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_3_3_10/PK_1_3_3_10/output.txt");

    int leftSide;
    int rightSide;
    int valOne, valTwo;

    in >> leftSide >> rightSide >> valOne >> valTwo;
    for (int i = leftSide; i < rightSide; ++i) {
        if (i % 10 == valOne || i % 10 == valTwo) {
            out << i << " ";
        }
    }
    in.close();
    out.close();
    return 0;
}