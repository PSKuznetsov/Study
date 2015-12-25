//
//  main.cpp
//  Stack_cont_7
//
//  Created by Paul Kuznetsov on 6/29/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <fstream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<stack<int>> v;

ifstream in ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Stack_cont_7/Stack_cont_7/input.txt");
ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Stack_cont_7/Stack_cont_7/output.txt");

inline void addValueToVector(int vector_n, int value) {
    
    v[vector_n].push(value);
    
}

inline void popValueFromVector(int vector_n) {
    
    out << v[vector_n].top() << " ";
    v[vector_n].pop();
    
}

inline void topValueFromVector(int vector_n) {
    
    out << v[vector_n].top() << " ";
    
}

void analyzeString(string str) {
    
    if (str[0] == 'P' && str[1] == 'U') {
        
        string inset = str.substr(str.find("(") + 1, str.size() - 1);
        
        string::size_type devPos = inset.find(",");
        
        
        int i = atoi((inset.substr(0, devPos)).c_str());
        int v = atoi((inset.substr(devPos + 1, str.size() - 1)).c_str());
        addValueToVector(i, v);
        
    }
    else if (str[0] == 'P' && str[1] == 'O') {
        
        int i = atoi((str.substr(str.find("(") + 1, str.size() - 1)).c_str());
        
        popValueFromVector(i);
        
    }
    else {
        
        int i = atoi((str.substr(str.find("(") + 1, str.find(")") - 1)).c_str());
        
        topValueFromVector(i);
    }
}

int main() {
    
    
    
    int n, k;
    in >> n >> k;
    
    v.reserve(n);
    
    string line;
    getline(in, line);
    
    while (!in.eof()) {
        
        getline(in, line);
        analyzeString(line);
        
    }
    in.close();
    out.close();
    
    return 0;
}
