//
//  main.cpp
//  Queue_cont_10
//
//  Created by Paul Kuznetsov on 6/30/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

void addValueToVector(int vector_n, int value, vector<queue<int>>& clstr) {
    
    clstr[vector_n].push(value);
    
}

void popValueFromVector(int vector_n, vector<queue<int>>& clstr, ofstream& out) {
    
    out << clstr[vector_n].front() << endl;
    clstr[vector_n].pop();
    
}

void topValueFromVector(int vector_n, vector<queue<int>>& clstr, ofstream& out) {
    
    out << clstr[vector_n].front() << endl;
    
}

void analizeString(string line, vector<queue<int>>& clstr, ofstream& out) {
    
    if (line[0] == 'P' && line[1] == 'U') {
        
        string inset = line.substr(line.find("(") + 1, line.size() - 1);
        
        string::size_type devPos = inset.find(",");
        
        
        int i = stoi(inset.substr(0, devPos));
        int v = stoi(inset.substr(devPos + 1, line.size() - 1));
        addValueToVector(i, v, clstr);
        
    }
    else if (line[0] == 'P' && line[1] == 'O') {
        
        int i = stoi(line.substr(line.find("(") + 1, line.size() - 1));
        
        popValueFromVector(i, clstr, out);
        
    }
    else {
        
        int i = stoi(line.substr(line.find("(") + 1, line.find(")") - 1));
        
        topValueFromVector(i, clstr, out);
    }
    
}

int main() {
    
    ifstream in ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Queue_cont_10/Queue_cont_10/input.txt");
    ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Queue_cont_10/Queue_cont_10/output.txt");
    
    int n, k;
    in >> n >> k;
    string line;
    
    vector<queue<int>> clstr (n);
    
    while (!in.eof()) {
        
        in >> line;
        analizeString(line, clstr, out);
        
    }
    
    return 0;
}
