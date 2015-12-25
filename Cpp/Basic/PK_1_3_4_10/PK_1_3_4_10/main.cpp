#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_3_4_10/PK_1_3_4_10/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Informatics tasks/Paul/PK_1_3_4_10/PK_1_3_4_10/output.txt");

    int n;
    in >> n;

    for (int i = 8; i >= 4 ; --i) {
        for (int j = 0; j < n; ++j) {
            out << i << " ";
        }
        n--;
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}