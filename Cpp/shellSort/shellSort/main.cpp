//
//  main.cpp
//  shellSort
//
//  Created by Paul Kuznetsov on 17/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
using namespace std;

int increment(long inc[], long size) {
    int p1, p2, p3, s;
    
    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2) {
            inc[s] = 8*p1 - 6*p2 + 1;
        }
        else {
            inc[s] = 9*p1 - 9*p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while(3*inc[s] < size);
    
    return s > 0 ? --s : 0;
}

template <class T>
void shellSort(T array[], long size) {
    long inc, i, j, seq[40];
    int s;
    
    // вычисление последовательности приращений
    s = increment(seq, size);
    while (s >= 0) {
        // сортировка вставками с инкрементами inc[]
        inc = seq[s--];
        
        for (i = inc; i < size; i++) {
            T temp = array[i];
            for (j = i-inc; (j >= 0) && (array[j] > temp); j -= inc)
                array[j+inc] = array[j];
            array[j+inc] = temp;
        }
    }
}


int main() {
    
    static int n;
    cin >> n;
    int arr[n];
    
    for (int  i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    shellSort(arr,n);
    
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
