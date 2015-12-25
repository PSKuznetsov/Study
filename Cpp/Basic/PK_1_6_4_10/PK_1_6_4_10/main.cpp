//
//  main.cpp
//  PK_1_6_4_10
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_4_10/PK_1_6_4_10/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_4_10/PK_1_6_4_10/output.txt");

    int n, m;
    in >> n >> m;
    int** arr = new int* [n];
    int* ansArray = new int[m];

    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            in >> arr[i][j];
        }
    }
    int iMin = INT32_MIN;
    bool state = false;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
             if (arr[i][j] >= 0 && !state) {
                 ansArray[j] = arr[j][i];
                 iMin = arr[i][j];
                 state = true;
             }
        }
        state = false;
        ansArray[j] = iMin;
        iMin = INT32_MIN;
    }

    for (int i = 0; i < m; ++i) {
        out << ansArray[i] << " ";
    }

    return 0;
}