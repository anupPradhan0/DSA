

// 75. Sort Colors
//Dutch National Flag Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// class Solution {
// public:
//     void sortColors(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//     }
// };


// class Solution {
// public:
//     void sortColors(vector<int>& arr) {
//         int n = arr.size();
//         int count0 = 0;
//         int count1 = 0;
//         int count2 = 0;

//         for (int i = 0; i < n; i++) {
//             if(arr[i] == 0) count0++;
//             else if (arr[i] == 1) count1++;
//             else count2++;
//         }
//         int idx = 0;
//         for (int i = 0; i < count0; i++) {
//             arr[idx++] = 0;
//         }
//         for (int i = 0; i < count1; i++) {
//             arr[idx++] = 1;
//         }
//         for (int i = 0; i < count2; i++) {
//             arr[idx++] = 2;
//         }
//     }
// };


// Dutch National Flag Algorithm
// 3 pointers = low , hid , high
// 0s = 0 to low -1
// 1s = low to mid -1
// 2s =  hig +1 to n -1
// unsort = mid to hig 

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low =  0;
        int mid = 0;
        int high = n-1;
        while (mid <= high) {
            if(arr[mid] == 0) { // 0
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) { // 1
                mid++;
            } else { // 2
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};