#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> firstVector;
    vector<int> ansVector;
    int n, tmp, counter = 0;
    cin >> n;
    ansVector.reserve(n);
    for (int i(0); i < n; i++) {
        cin >> tmp;
        firstVector.push_back(tmp);
    }
    for (int i(n - 1); i >= 0; i--) {
        if (firstVector[i] < 0){
            ansVector[i] = 0;
            counter = 1;
        }
        else {
            ansVector[i] = counter;
            counter ++;
        }
    }
    for (int i(0); i < n; i++) {
        cout << ansVector[i] << " ";
    }

    return 0;
}