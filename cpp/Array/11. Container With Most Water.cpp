
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// class Solution {
// public:
//     int maxArea(vector<int>& height) {

//         int maxWa = 0;
//         int n = height.size();

//         for (int i = 0; i < n; i++)
//         {
//             int w = 0;
//             int h = 0;
//             for(int j = i+1; j < n; j++) {
//                 w = j-i; // we are doing The index not the actual value 
//                 h = min(height[i], height[j]);
//                 maxWa = max(maxWa, w * h);
//             }
//         }
//         return maxWa;
//     }
// };

// Optimal Approach (2 pointer)

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;
        int maxWa = 0;

        while (left < right)
        {
            int w = right - left;
            int h = min(height[left], height[right]);
            maxWa = max(maxWa, w * h);

            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
            
        }
        return maxWa;
    }
};