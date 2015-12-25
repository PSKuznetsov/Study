//
//  main.cpp
//  Algorithm_I_11
//
//  Created by Paul Kuznetsov on 7/1/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#pragma mark - structur

struct Point {
    
    int x;
    int y;
};

#pragma mark - Predicate

bool ifLeftSide(Point p) {
    
    return p.x < 0;
}

#pragma mark - Helper

int distanceFromOrigin(Point& p) {
    
    return sqrt(p.x * p.x + p.y * p.y);
    
}

#pragma mark - Methods

void deleteLeftSidePoints(vector<Point>& points) {
    
    vector<Point>::iterator pos = points.begin();
    
    for (vector<Point>::iterator it = points.begin(); it != points.end(); it++) {
        
        pos = find_if(pos, points.end(), ifLeftSide);
        
        if(pos != points.end())
            points.erase(pos);
    }
    
}

int calculatePointsForPoint(Point& point, vector<Point>& points) {
    
    int summ = 0;
    
    vector<Point>::iterator pos = points.begin();
    
    for (vector<Point>::iterator it = points.begin(); it != points.end(); it++) {
        
        pos = find_if(pos, points.end(), [point](const Point& p){return (p.x < point.x || p.y < point.y);});
        
        if (pos != points.end()) {
            
            summ++;
        }
        
    }
    
    return summ;
}


Point& findLastPointWithR(vector<Point>& points, int R) {
    
    int maxDistance = 0;
    
    Point* p = new Point;
    
    for (int i = 0; i < points.size(); i++) {
        
        if (distanceFromOrigin(points[i]) >= R && distanceFromOrigin(points[i]) > maxDistance) {
            
            maxDistance = distanceFromOrigin(points[i]);
            p = &points[i];
        }
        
    }
    return *p;
}


vector<int> createSummVectorFromPoints(vector<Point>& points) {
    
    vector<int> summVector;
    
    for (int i = 0; i < points.size(); ++i) {
        
        summVector.push_back(points[i].x + points[i].y);
    }
    sort(summVector.begin(), summVector.end());
    
    return summVector;
}

#pragma mark - Main

int main() {
    
    ifstream in ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Algorithm_I_11/Algorithm_I_11/input.txt");
    ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Algorithm_I_11/Algorithm_I_11/output.txt");
    
    int n;
    
    in >> n;
    
    vector<Point>points;
    Point cur;
    
    for (int i = 0; i < n; ++i) {
        
        in >> cur.x;
        in >> cur.y;
        
        points.push_back(cur);
    }
    
    cur.x = 11;
    cur.y = 11;
    
    deleteLeftSidePoints(points);
    
    int amountOfDesireItems = calculatePointsForPoint(cur, points);
    
    for (int i = 0; i < points.size(); ++i) {
        
        out << points[i].x << " " << points[i].y << endl;
    }
    out << endl << "Amount of desire elements is: " << amountOfDesireItems << " ";
    
    
    cur = findLastPointWithR(points, 10);
    
    out << endl << "Last point: " << cur.x << ";" << cur.y << endl;
    
    vector<int> resultVector = createSummVectorFromPoints(points);
    
    for (int i = 0; i < resultVector.size(); ++i) {
        
        out << resultVector[i] << " ";
    }
    
    return 0;
}
