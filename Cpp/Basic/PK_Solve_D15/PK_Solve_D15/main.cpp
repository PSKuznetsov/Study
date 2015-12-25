//
//  main.cpp
//  PK_Solve_D15
//
//  Created by Paul Kuznetsov on 21/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int size = 0;
    cin >> size;
    int maxValue = INT_MIN;
    int preSumma = 0;
    int summa = 0;
    int var = 0;
    for (int index = 0; index < size; index++)
    {
        cin >> var;
        maxValue = max(maxValue, var);
        (preSumma + var > 0) ? preSumma += var : preSumma = 0;
        summa = max(preSumma, summa);
    }

    cout << (!summa && !preSumma ? maxValue : summa);
    return 0;
}