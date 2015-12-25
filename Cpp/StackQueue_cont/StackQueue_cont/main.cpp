//
//  main.cpp
//  StackQueue_cont
//
//  Created by Paul Kuznetsov on 6/29/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    
    ifstream in ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/StackQueue_cont/StackQueue_cont/input.txt");
    ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/StackQueue_cont/StackQueue_cont/output.txt");
    
    int n;
    queue<int> queueOfNumbers;
    stack<int> stackOfNumbers;
    
    while (in >> n) {
        
        queueOfNumbers.push(n);
    }
    
    while (!queueOfNumbers.empty()) {
        
        int tempDigit = queueOfNumbers.front();
        
        if (tempDigit % 2 != 0 && tempDigit % 3 == 0) {
            
            stackOfNumbers.push(tempDigit);
        }
        queueOfNumbers.pop();
    }
    
    while (!stackOfNumbers.empty()) {
        
        out << stackOfNumbers.top() << " ";
        stackOfNumbers.pop();
    }
    
    return 0;
}
