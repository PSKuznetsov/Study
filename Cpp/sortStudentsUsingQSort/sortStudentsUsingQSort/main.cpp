//
//  main.cpp
//  sortStudentsUsingQSort
//
//  Created by Paul Kuznetsov on 28/04/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Students.h"
using namespace std;

template<class T>
void quickSortR(T* a, long N) {
    
    long i = 0, j = N;
    T temp, p;
    
    p = a[ N>>1 ];
    
   
    do {
        while ( a[i] < p ) i++;
        while ( a[j] > p ) j--;
        
        if (i <= j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++; j--;
        }
    } while ( i<=j );
    
    
    if ( j > 0 ) quickSortR(a, j);
    if ( N > i ) quickSortR(a+i, N-i);
}

int main() {
    
    ifstream in ("/Users/NSCoder/Documents/Xcode/C++/sortStudentsUsingQSort/sortStudentsUsingQSort/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Xcode/C++/sortStudentsUsingQSort/sortStudentsUsingQSort/output.txt");
    
    int n;
    in >> n;
    string tmp;
    int d_tmp;
    Students* arrayOfStudents = new Students[n];
    
    for (int i = 0; i < n; ++i) {
        in >> tmp;
        arrayOfStudents[i].setFirstName(tmp);
        in >> tmp;
        arrayOfStudents[i].setLastName(tmp);
        in >> d_tmp;
        arrayOfStudents[i].setDayOfMonth(d_tmp);
        in >> d_tmp;
        arrayOfStudents[i].setNumberOfMonth(d_tmp);
    }
    
    quickSortR(arrayOfStudents, n);
    
    for (int i = 0; i < n; ++i) {
        out << arrayOfStudents[i].getFirstName() << " " << arrayOfStudents[i].getLastName() << " " << arrayOfStudents[i].getDayOfMonth() << " " << arrayOfStudents[i].getNumberOfMonth() << endl;
    }
    
    
    return 0;
}
