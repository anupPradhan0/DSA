

// 219. Contains Duplicate II

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& arr, int k) {
//         int n = arr.size();
//         for (int i = 0; i < n ; i++) {
//             for(int j = 0; j < n; j++) {
//                 if (i != j && arr[i] == arr[j] && abs(i-j) <= k) return true;
//                 else continue;
//             }
//         }
//         return false;
//     }
// };

