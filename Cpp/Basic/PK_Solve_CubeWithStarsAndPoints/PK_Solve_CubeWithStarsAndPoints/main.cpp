//
//  main.cpp
//  PK_Solve_CubeWithStarsAndPoints
//
//  Created by Paul Kuznetsov on 21/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
using namespace std;
char a[1000][1000];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int i1 = 1001, in=-1, j1 = 1001, jn=-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') {
            in = max(i, in);
            jn = max(jn, j);
            i1 = min(i1, i);
            j1 = min(j1, j);
        }
    }
}
printf("%d",max(in - i1 + 1, jn - j1 + 1));
return 0;
}