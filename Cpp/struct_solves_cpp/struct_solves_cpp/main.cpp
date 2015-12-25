//
//  main.cpp
//  struct_solves_cpp
//
//  Created by Paul Kuznetsov on 08/12/14.
//  Copyright (c) 2014 Paul Kuznetsov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

ifstream in("/Users/NSCoder/Documents/C++ projects/struct_solves_cpp/struct_solves_cpp/input.txt");
ofstream out("/Users/NSCoder/Documents/C++ projects/struct_solves_cpp/struct_solves_cpp/output.txt");

struct Toy {
    string id;
    double price;
    int lowEdge;
    int highEdge;
};

int main() {
    int percent;
    int amount;
    in >> percent >> amount;
    Toy* newToy = new Toy[amount];
    
    for (int i = 0; i < amount; i++) {
    
        in >> newToy[i].id;
        in >> newToy[i].price;
        newToy[i].price = newToy[i].price - (newToy[i].price/100 * percent);
        in >> newToy[i].lowEdge;
        in >> newToy[i].highEdge;
        
        out << "Toy id: " << newToy[i].id<< endl;
        
        out << "Toy price: " << newToy[i].price << endl;
        out << "Toy's age limit from: " << newToy[i].lowEdge << " ";
        out << "to: " << newToy[i].highEdge << endl;
        out << "-------------------------------------------" << endl;
    
    }
    
    
    return 0;
}
