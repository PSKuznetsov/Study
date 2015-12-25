//
//  main.cpp
//  selectSort
//
//  Created by Paul Kuznetsov on 17/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
void selectSort(T a[], long size) {
    long i, j, k;
    T x;
    
    for (i = 0; i < size; i++) {   	// i - номер текущего шага
        k=i; x=a[i];
        
        for (j = i + 1; j < size; j++) { 	// цикл выбора наименьшего элемента
            if (  a[j] < x ) {
                k = j;
                x = a[j];	        // k - индекс наименьшего элемента
            }
        }
        
        a[k] = a[i];
        a[i] = x;   	// меняем местами наименьший с a[i]
    }
}


int main() {
    
    static int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    selectSort(arr, n);
    
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
