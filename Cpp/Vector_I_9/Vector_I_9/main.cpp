//
//  main.cpp
//  Vector_I_9
//
//  Created by Paul Kuznetsov on 6/30/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>

using namespace std;

void insertElements(vector<int>&v, int x, int y) {
    
    if (v.size()%2 == 0) {
        
        int pos = (int)v.size()/2;
        v.insert(v.begin() + pos, x);
        v.insert(v.begin() + pos + 1, y);
        
    }
    else {
        
        int pos = (int)v.size()/2;
        v.insert(v.begin() + pos, x);
        v.insert(v.begin() + pos + 2, y);
    }
    
}

void changeElements(list<int>&l) {
    
    int front_one, front_two;
    
    front_one = l.front();
    l.pop_front();
    
    front_two = l.front();
    l.pop_front();
    
    front_one ++;
    front_two ++;
    
    l.push_front(front_two);
    l.push_front(front_one);
    
    int back_one, back_two;
    
    back_one = l.back();
    l.pop_back();
    
    back_two = l.back();
    l.pop_back();
    
    back_one ++;
    back_two ++;
    
    l.push_back(back_two);
    l.push_back(back_one);
}

int main() {
    
    ifstream in  ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Vector_I_9/Vector_I_9/input.txt");
    ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Vector_I_9/Vector_I_9/output.txt");
    
    vector<int> v;
    list<int> l;
    
    int x, y, n;
    in >> x >> y;
    
    while (!in.eof()) {
        
        in >> n;
        v.push_back(n);
        
    }
    in.close();
    
    
    
    insertElements(v, x, y);
    
    for (int i = 0; i < v.size(); ++i) {
        out << v[i] << " ";
    }
    
    out << endl;
    
    in.open("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Vector_I_9/Vector_I_9/input.txt");
    in >> x >> y;
    
    while (!in.eof()) {
        
        in >> n;
        l.push_back(n);
        
    }
    
    changeElements(l);
    
    while (!l.empty()) {
        
        out << l.front() << " ";
        l.pop_front();
    }
    
    
    return 0;
}
