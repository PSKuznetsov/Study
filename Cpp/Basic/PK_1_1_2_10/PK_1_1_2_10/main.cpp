#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_1_2_10/PK_1_1_2_10/input.txt");
    ofstream out("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_1_2_10/PK_1_1_2_10/output.txt");

    double value;
    in >> value;
    out << "Answer is: " << pow(value, (double)1/3) << endl;

    return 0;
}