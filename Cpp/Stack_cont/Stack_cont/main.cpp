//
//  main.cpp
//  Stack_cont
//
//  Created by Paul Kuznetsov on 6/29/15.
//  Copyright © 2015 Paul Kuznetsov. All rights reserved.
//

#include <string>
#include <stack>
#include <fstream>
#include <set>

using namespace std;

int main() {
    
    ifstream in ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Stack_cont/Stack_cont/input.txt");
    ofstream out ("/Users/PSKuznetsov/Documents/Xcode/C++/Practise/Stack_cont/Stack_cont/output.txt");
    
    
//--------------------------------------------------//
    set<char> st;
    
    st.insert('!');
    st.insert(';');
    st.insert('?');
    st.insert('.');
    st.insert(',');
    st.insert('-');
    st.insert(':');
    st.insert(';');
    st.insert(')');
    st.insert('(');
    st.insert('\'');
    st.insert('"');
//--------------------------------------------------//
    stack<char> stck;
    
    string curWord;
    
    while (in >> curWord) {
        
        for (int i = 0; i < curWord.length(); ++i) {
            
            if (st.find(curWord[i]) != st.end()) {
                
                stck.push(curWord[i]);
            }
        }
        
    }
    
    while (!stck.empty()) {
        
        out << stck.top();
        stck.pop();
    }
    
    return 0;
}
