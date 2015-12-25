//
//  main.cpp
//  rectMatrix
//
//  Created by Paul Kuznetsov on 15/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    static int n, m;
    cin >> n >> m;
    
    int matrix[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    int ansMatrix[m];
    bool flag = true;
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n && flag; ++i) {
            
            if (matrix[i][j] < 0) {
                ansMatrix[j] = matrix[i][j];
                flag = false;
            }
            else {
                ansMatrix[j] = 0;
            }
        }
        flag = true;
    }
    
    for (int i = 0; i < m; ++i) {
        cout << ansMatrix[i] << " " ;
    }
    
    return 0;
}
