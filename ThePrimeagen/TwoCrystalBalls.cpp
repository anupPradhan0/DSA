// Implementing Two Crystal Balls

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int TwoCrystalBalls(bool arr[], int n) {
    if (n <= 0) return -1;

    int jump = static_cast<int>(sqrt(n));
    if (jump <= 0) jump = 1;

    int i = jump;
    // Jump in blocks until we find a broken ball or exceed array
    while (i < n && !arr[i]) {
        i += jump;
    }

    // Linear search within the previous block
    int start = max(0, i - jump);
    int end = min(i, n - 1);
    for (int j = start; j <= end; ++j) {
        if (arr[j]) return j;
    }

    return -1;
}

int main() {
    bool arr[] = {false, false, false, true, true};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << TwoCrystalBalls(arr, n) << endl; // expected output: 3
    return 0;
}

// Output:
// 3