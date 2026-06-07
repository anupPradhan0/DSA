// Implementing Binary Search

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int target) {
    int lo = 0;
    int hi = sizeof(arr)/sizeof(arr[0]) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            lo = mid + 1; // Search in the right half
        } else {
            hi = mid -1; // Search in the left half
        }
    }
    return -1; // Target not found
}


int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90}; // Sorted array
    int target = 25;
    int result = BinarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}

/* Output:
Element found at index: 3
Nice hahahhahahahahaahahahhhahaahhhahhaahh
*/