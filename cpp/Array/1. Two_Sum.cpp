
// 1 Two_Sum 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {

//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 if(nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };


// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& arr, int target) {
//         int n = arr.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i+1; j < n; j++) {
//                 if(arr[i] + arr[j] == target) {
//                     return {i,j};
//                 };
//             };
//         };
//         return {};
//     }
// };

// 2 pointer

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& arr, int target) {
//         vector<pair<int, int>> orig;

//         for (int i = 0; i < arr.size(); ++i) {
//             orig.push_back({arr[i], i});
//         }
//         sort(orig.begin(), orig.end());

//         int st = 0;
//         int end = arr.size() - 1;

//         while (st < end) {
//             int sum = orig[st].first + orig[end].first;

//             if (sum == target) {
//                 return {orig[st].second, orig[end].second};
//             } else if (sum < target) {
//                 st++;
//             } else {
//                 end--;
//             }
//         }
//         return {};
//     }
// };


// Hashing

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int>myMap;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            int fir = arr[i];
            int sec = target - fir;

            if (myMap.find(sec)!= myMap.end()) {
                ans.push_back(i);
                ans.push_back(myMap[sec]);
                break;
            };
            myMap[fir] = i;

        }
        return ans;
    }
};
