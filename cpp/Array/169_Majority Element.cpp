#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         for(int val : nums) {
//             int count = 0;
//             for(int el : nums) {
//                 if (val == el) {
//                     count++;
//                 }
//             }
//             if(count > nums.size() / 2) {
//                 return val;
//             }
//         }
//         return -1;
//     }
// };


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         sort(nums.begin(), nums.end());

//         int freq = 1;
//         int ans = nums[0];
//         int n = nums.size(); 
//         for (int i = 1; i < n; i++)
//         {
//             if(nums[i] == nums[i-1]) {
//                 freq++;
//             }
//             else {
//                 freq = 1;
//                 ans = nums[i];
//             }

//             if(freq > n / 2) {
//                 return ans;
//             }
//         }
//         return ans;
//     }
// };


// MOORIS voting Algo

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int fre = 0;
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(fre == 0) {
                ans = nums[i];
            }
            if(ans == nums[i]) {
                fre++;
            }
            else {
                fre--;
            }

        }

        return ans;
    }
};