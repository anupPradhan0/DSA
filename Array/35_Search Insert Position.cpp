#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] >= target) {
                return i;
            }
            else if (i == nums.size()-1) {
                return i+1;
            }

        }
        return {} ;
    }
};