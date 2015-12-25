//
//  overideF.cpp
//  OverideFunc_10
//
//  Created by Paul Kuznetsov on 03/03/15.
//  Copyright (c) 2015 Paul Kuznetsov. All rights reserved.
//

#include "overideF.h"

double getResultOfFunc(double x) {
    if (x + 2 <= 1) {
        return x * x;
    }
    else if ((x + 2 > 1) && (x + 2 < 10)) {
        return (double)1 / (x * x - 1);
    }
    return x + 2;
}

void getResultOfFunc(double x, double& y) {
    if (x + 2 <= 1) {
        y = x * x;
    }
    else if ((x + 2 > 1) && (x + 2 < 10)) {
        y = (double)1 / (x * x - 1);
    }
    y = x + 2;
}