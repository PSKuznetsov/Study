//
//  main.cpp
//  PK_1_6_1_10
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_1_10/PK_1_6_1_10/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_1_10/PK_1_6_1_10/output.txt");
    int n;
    in >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        in >> arr[i];
    }

    int sum = 0;

    for (int j = 0; j < n; ++j) {
        if (arr[j] % 9 == 0) {
            sum += arr[j];
        }
    }

    out << sum << endl;
    in.close();
    out.close();

    return 0;
}