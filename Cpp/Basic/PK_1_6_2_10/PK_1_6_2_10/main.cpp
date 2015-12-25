#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_2_10/PK_1_6_2_10/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_6_2_10/PK_1_6_2_10/output.txt");

    int n, max = INT32_MIN;
    in >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        in >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    out << max << endl;
    in.close();
    out.close();
    return 0;
}