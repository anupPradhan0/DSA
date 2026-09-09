// Bubble Sort O(n^2) time complexity

#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n -1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    BubbleSort(arr);
    cout << "Sorted array: \n";
    for (int i : arr)
        cout << i << " ";
    return 0;
}