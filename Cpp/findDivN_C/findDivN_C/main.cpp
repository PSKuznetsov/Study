//
//  main.cpp
//  findDivN_C
//
//  Created by Paul Kuznetsov on 15/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int findDivN(int n) {
    
    int ans = 0;
    
    if (n == 0) {
        
        return 0;
    }
    else if (n == 1) {
        
        return 1;
    }
    else {
       
        for (int i = 1; i <= sqrt((double)n); ++i) {
            
            if (n % i == 0) {
                if (i * i == n) {
                    ans++;
                }
                else {
                    
                    ans+=2;
                }
            }
        }
    }
    
    
    return ans;
}

int main() {
    
    int n;
    
    cin >> n;
    cout << findDivN(n) << endl;
    
    return 0;
}
