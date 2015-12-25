#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_3_15/PK_1_6_3_15/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_3_15/PK_1_6_3_15/output.txt");

    int n;
    in >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> arr[i][j];
        }
    }

    bool state = true;

    for (int i = 0; i < n && state; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != arr[j][i]) {
                state = false;
                continue;
            }
        }
    }

    out << (state ? "Matrix is good" : "Matrix is not symmetric") << endl;

    in.close();
    out.close();

    return 0;
}