#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void qsort(int* a, int left, int right) {
    
    int i = left;
    int j = right;
    
    int m = a[rand() % (right - left + 1) + left];
    
    while (i <= j) {
        
        while (a[i] < m) {
            ++i;
        }
        while (a[j] > m) {
            --j;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (left < j) {
        qsort(a, left, j);
    }
    if (i < right) {
        qsort(a, i, right);
    }
}

int main() {
    
    ifstream in ("/Users/NSCoder/Documents/Xcode/C++/cppQsort/cppQsort/input.txt");
    ofstream out ("/Users/NSCoder/Documents/Xcode/C++/cppQsort/cppQsort/output.txt");
    
    int mas[6];
    
    for (int i = 0; i < 6; ++i) {
        in >> mas[i];
    }
    
    qsort(mas, 0, 5);
    
    for (int i = 0; i < 6; ++i) {
        out << mas[i] << " ";
    }
    
    return 0;
}
