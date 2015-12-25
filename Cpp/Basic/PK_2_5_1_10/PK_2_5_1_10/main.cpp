//
//  main.cpp
//  PK_2_5_1_10
//
//  Created by Paul Kuznetsov on 22/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point {
    Point();

    Point(int x, int y);

    int _x;
    int _y;
};

Point::Point(int x, int y) {
    _x = x;
    _y = y;
}

Point::Point() {

}

struct Sphere {
private:
    double _radius;
public:
    void setRadius(double radius);
    Point findGoodPointInArray(Point* arr, int lenght);
};

void Sphere::setRadius(double radius) {
    _radius = radius;
}

Point Sphere::findGoodPointInArray(Point *arr, int lenght) {

    Point ansPoint = Point(0, 0);
    int* amountOfValue = new int[lenght];
    for (int i = 0; i < lenght; ++i) {
        amountOfValue[i] = 0;
    }

    for (int i = 0; i < lenght; ++i) {
        for (int j = 0; j < lenght; ++j) {
            if (_radius >= sqrt(pow(arr[j]._x - arr[i]._x, 2.0) + pow(arr[j]._y - arr[i]._y, 2.0))) {
                amountOfValue[i]++;
            }
        }
    }

    int max = INT32_MIN;

    for (int i = 0; i < lenght; ++i) {
         if (amountOfValue[i] > max) {
             max = amountOfValue[i];
         }
    }

    ansPoint._x = arr[max]._x;
    ansPoint._y = arr[max]._y;

    return ansPoint;
}

int main() {
    ifstream in  ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_2_5_1_10/PK_2_5_1_10/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_2_5_1_10/PK_2_5_1_10/output.txt");

    int amount;
    double radius;
    in >> amount >> radius;
    Point* points = new Point[amount];
    Sphere* sphere = new Sphere();

    sphere->setRadius(radius);

    for (int i = 0; i < amount; ++i) {
        in >> points[i]._x >> points[i]._y;
    }
    Point ans = sphere->findGoodPointInArray(points, amount);
    out << "Answer is: " << ans._x << " " << ans._y << endl;
    in.close();
    out.close();
    return 0;
}

