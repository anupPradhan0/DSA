

// 217. Contains Duplicate


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// [1,2,3,4]
// class Solution { // O(N2)
// public:
//     bool containsDuplicate(vector<int>& arr) {
//         int n = arr.size();
//         for (int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 if(arr[i] == arr[j]) {
//                     return true;
//                 }
//             } 
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() -1; i++) {
            if(arr[i] == arr[i+1]) return true;
        }
        return false;
    }
};