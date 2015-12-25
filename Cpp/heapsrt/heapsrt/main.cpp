//
//  main.cpp
//  heapsrt
//
//  Created by Paul Kuznetsov on 17/06/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void pushdown ( int *a, int first, int last)
{
    int r = first;
    while ( r <= last/2) // есть ли сыновья
    {
        
        if ( last == 2*r )
        {
            if (a[r] > a[2*r])
                swap (a[r],a[2*r]);
            r = last;
        }
        else if (a[r] > a[2*r] && a[2*r] <= a[2*r+1])
        {
            swap(a[r],a[2*r]);
            r=2*r;
        }
        else if (a[r] > a[2*r+1] && a[2*r+1] < a[2*r])
        {
            swap (a[r],a[2*r+1]);
            r = 2*r+1;
        }
        else
            r = last;
    }
}

void heapsort (int *a, int n)
{
    for ( int i=n/2; i>=1; i--)
        pushdown(a,i,n);
    for ( int i=n; i>=2; i--)
    {
        swap(a[1],a[i]);
        pushdown(a,1,i-1);
    }
}


int main() {
    
    int* a = new int [7];
    int n = 6;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    heapsort(a, n);
    
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    
    return 0;
}
