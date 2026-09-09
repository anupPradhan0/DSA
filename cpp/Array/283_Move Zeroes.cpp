

// 283. Move Zeroes


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// class Solution {
// public:
//     vector<int> moveZeroes(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> ans;
//         int val0 = 0;
//         for (int i = 0; i < n; i++) {
//             if(arr[i] != 0) {
//                 ans.push_back(arr[i]);
//             } else {
//                 val0++;
//             }
//         }
//         while (val0--) {
//             ans.push_back(0); 
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int j = 0;

        // Step 1: Move non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[j] = arr[i];
                j++;
            }
        }

        // Step 2: Fill the remaining positions with zeros
        while (j < n) {
            arr[j] = 0;
            j++;
        }
    }
};
