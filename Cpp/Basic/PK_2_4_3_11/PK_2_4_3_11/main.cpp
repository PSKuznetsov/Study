#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {

    ofstream out("binary.dat", ios::binary);
    int n;
    double dblValue;
    cout << "Enter number of double values and your double value: ";
    cin >> n >> dblValue;
    for (double i = 0; i < n; i+=0.5) {
        out.write((char*)&i, sizeof(i));
    }

    out.close();
    ifstream in("binary.dat", ios::binary);

    double tmpValue;
    in.seekg(sizeof(double));

    while (in.peek() != EOF) {
        in.read((char *)&tmpValue, sizeof(double));
        if (tmpValue > dblValue) {
            cout << "Double value: " << tmpValue << endl;
        }
        in.seekg(sizeof(double), ios::cur);
    }

    in.close();
    return 0;
}