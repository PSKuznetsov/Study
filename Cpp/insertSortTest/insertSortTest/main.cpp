//
//  main.cpp
//  insertSortTest
//
//  Created by Paul Kuznetsov on 17/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
void insertSort(T array[], long size) {
    
    T x;
    long i,j;
    
    for (i = 0; i < size; ++i) {
       
        x = array[i];
       
        for (j = i - 1; j >= 0 && array[j] > x; --j) {
            array[j + 1] = array[j];
        }
        
        array[j + 1] = x;
        
    }
}

int main() {
    
    static int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    insertSort(arr, n);
    
    for (int  i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
