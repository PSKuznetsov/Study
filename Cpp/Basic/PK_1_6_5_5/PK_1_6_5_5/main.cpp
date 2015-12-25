//
//  main.cpp
//  PK_1_6_5_5
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int* createDynamicArrayWithSize(int size){
    int* arr = new int[size];
    return arr;
}

int* deleteObjectsFromArrayAtIndexes(int* arr, int indexL, int indexR, int& lenght){
    int slideIndex = 1;
    indexL = min(indexL, indexR);
    indexR = max(indexL, indexR);
    if (indexR > lenght || indexL < 0) {
        return arr;
    }
    else {
        for (int i = indexL; i < lenght; ++i) {
            arr[i] = arr[indexR + slideIndex];
            slideIndex++;
        }
        slideIndex = indexR - indexL + 1;
        lenght -= slideIndex;
    }
    return arr;
}

int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_5_5/PK_1_6_5_5/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_5_5/PK_1_6_5_5/output.txt");

    int n, left, right;
    in >> n >> left >> right;

    int* arr = createDynamicArrayWithSize(n);
    for (int i = 0; i < n; ++i) {
        in >> arr[i];
    }

    arr = deleteObjectsFromArrayAtIndexes(arr, left, right, n);

    for (int i = 0; i < n; ++i) {
        out << arr[i] << " ";
    }

    return 0;
}