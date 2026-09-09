
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Linear Search Solution
// [1,3,5,8,6,4]
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {

//         int n = arr.size();

//         for (int i = 1; i < n ; i++){
//             if(arr[i] > arr[i-1] && arr[i] > arr[i+1] ){
//                 return i;
//             }
//         }   
//         return -1;
//     }
// };

// Binary Search

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // int sta = 0;
        // int end  = arr.size() -1;
        int sta = 1;
        int end  = arr.size() -2;

        while (sta <= end) {
            int mid = sta + (end - sta) / 2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            } else if (arr[mid-1] < arr[mid] ) {
                sta = mid+1;
            } else {
                end = mid-1;
            }
        }
        return -1;
    }
};
