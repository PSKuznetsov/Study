#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_1_1_10/PK_1_1_1_10/input.txt");
    ofstream out("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_1_1_10/PK_1_1_1_10/output.txt");

    double x;
    in >> x;
    out << "Answer is: " << 1 + x/3 + abs(x) + (pow(x, 3) + 4)/2;

    return 0;
}