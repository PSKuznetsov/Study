//
//  main.cpp
//  PK_1_3_1_10
//
//  Created by Paul Kuznetsov on 21/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    Point newPoint;
    in >> newPoint.x >> newPoint.y;
    if (newPoint.y > -abs(newPoint.x) && newPoint.x < -100) {
        out << "No";
    }
    else out << (newPoint.y < -abs(newPoint.x) && newPoint.x > -100 ? "Yes" : "On the edge");

    return 0;
}