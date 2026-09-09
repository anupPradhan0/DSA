
// 303. Range Sum Query - Immutable

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>q
#include <unordered_map>
using namespace std;


// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]
class NumArray {
private:
    vector<int> nums;

public:
    NumArray(vector<int>& arr) {
        nums = arr;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }
        return sum;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */




class NumArray {
private:
    vector<int> prefix;  // prefix[i] will store sum from 0 to i

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);
        if (n > 0) {
            prefix[0] = nums[0];
            for (int i = 1; i < n; i++) {
                prefix[i] = prefix[i - 1] + nums[i];
            }
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
