// Aggressive Cows
// Hard

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool isValid(vector<int> arr, int n, int c , int maxPossible) {
    int cow = 1;
    int lastST = arr[0];
    for (int i = 1; i < n; i++) {
        if(arr[i] - lastST >=  maxPossible) {
            cow++;
            lastST = arr[i];
        }
        
        if(cow == c) {
            return true;
        }

    }
    return false;
}

int aggCows(vector<int> arr, int n , int c) {

    sort(arr.begin(), arr.end());
    if(c > n) return -1;
    int sta = 1;
    int end = arr[n-1] - arr[0];
    int ans = 0;
    while (sta <= end) {
        int mid = sta + (end - sta ) / 2;

        if(isValid(arr, n , c , mid)) {
            ans = mid;
            sta = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}


int main() {

    vector<int> arr = {1, 2, 8, 4, 9};
    int n = 5 , c = 3;

    cout<< aggCows(arr, n, c) << endl;

}