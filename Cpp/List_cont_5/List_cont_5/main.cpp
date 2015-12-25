//
//  main.cpp
//  List_cont_5
//
//  Created by Paul Kuznetsov on 6/30/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {
    
    ifstream in ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/List_cont_5/List_cont_5/input.txt");
    ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/List_cont_5/List_cont_5/output.txt");
    
    int n;
    
    list<int>l;
    
    while (in >> n) {
    
        l.push_back(n);
    }
    
    int insertValue = l.back();
    l.pop_back();
    
    int insertTriger = l.back();
    l.pop_back();
    
    for (list<int>::iterator i = l.begin(), j = l.end(); i != j; i++) {
        
        int cur = *i;
        if (cur == insertTriger) {
            list<int>::iterator it = i;
            it++;
            l.insert(it, insertValue);
        }
        
    }
    
    for (list<int>::iterator i = l.begin(), j = l.end(); i != j; i++) {
        
        out << *i << " ";
        
    }
    
    return 0;
}
