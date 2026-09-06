// 1. Two Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;


// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = size(arr);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == target ) {
                    return {i, j};
                }
            }
        }
        
    }
};
