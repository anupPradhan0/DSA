
// Painter's Partition Problem
// hard
// Codechef


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool isValid(vector<int> arr , int n, int m, int maxPossible) {
    int people = 1;
    int time = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] > maxPossible) return false;

        if(time + arr[i] <= maxPossible) {
            time += arr[i];
        } else {
            people++;
            time = arr[i];
        }
    }
    return people <= m ? true : false;
}

int painterPar(vector<int> arr, int n, int m ) {
    // edge casee
    if(m > n) return -1;
    // to cal the sum or the ending point
    int sum = 0;
    int maxVal = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    // range of possible ans
    int sta = maxVal;
    int end = sum;
    int ans = 0;
    while (sta <= end) {
        int mid = sta + (end - sta) / 2;
        if(isValid(arr, n , m, mid)) {
            ans = mid;
            end = mid-1;
        } else {
            sta = mid + 1;
        }
    }
    return ans;
}


int main() {

    vector<int> arr = {40, 30 , 10, 20};
    int n = 4 , m = 2;

    cout<< painterPar(arr, n, m) << endl;

}