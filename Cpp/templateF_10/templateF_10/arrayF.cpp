//
//  arrayF.cpp
//  templateF_10
//
//  Created by Paul Kuznetsov on 03/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "arrayF.h"

template < class T, class U >
T* createArray(int n, int m) {
    T* array = new T[n];
    
    for (int i = 0; i < n; ++i) {
        array[i] = new U[m];
    }
    
    return array;
}