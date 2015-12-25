#include <iostream>
#include <fstream>
using namespace std;

int getAnswerFromNumber(int number) {
    return number % 2 != 0 ? 0 : number / 2;
}

int main() {
    ifstream in ("input.txt");
    ofstream out("output.txt");
    int number;
    in >> number;
    out << getAnswerFromNumber(number) << endl;
    in.close();
    out.close();
    return 0;
}