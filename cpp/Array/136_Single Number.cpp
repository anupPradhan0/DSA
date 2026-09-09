#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =  0;
        for(int val : nums) {
            ans = ans ^ val;
        }
        return ans;
    }
};