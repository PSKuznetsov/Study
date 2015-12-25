//
//  main.cpp
//  PK_1_6_6_13
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

struct minValue {
    int imin = 0;
    int jmin = 0;
    int min = INT32_MAX;
};

int** createDynamicArrayWithSizes(int row, int column) {
    int** arr = new int*[row];
    for (int i = 0; i < row; ++i) {
        arr[i] = new int [column];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

minValue findMinObjectInArrayWithSize(int** arr, int row, int column) {
    minValue minValueOFArray = minValue();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (arr[i][j] < minValueOFArray.min) {
                minValueOFArray.min = arr[i][j];
                minValueOFArray.imin = i;
                minValueOFArray.jmin = j;
            }
        }
    }
    return minValueOFArray;
}

int** deleteRowAndColumnInArrayWithMinValue(int** arr, minValue minV, int row, int column) {

    for (int i = minV.imin; i < row - 1; ++i) {
        for (int j = 0; j < column; ++j) {
              arr[i][j] = arr[i + 1][j];
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = minV.jmin; j < column - 1; ++j) {
             arr[i][j] = arr[i][j + 1];
        }
    }
    return arr;
}

int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_6_13/PK_1_6_6_13/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_6_13/PK_1_6_6_13/output.txt");

    int n, m;
    in >> n >> m;
    int** arr = createDynamicArrayWithSizes(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
             in >> arr[i][j];
        }
    }

    minValue minV = findMinObjectInArrayWithSize(arr, n, m);
    arr = deleteRowAndColumnInArrayWithMinValue(arr, minV, n, m);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            out << arr[i][j] << " ";
        }
        out << endl;
    }


    return 0;
}