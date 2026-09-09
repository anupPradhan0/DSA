
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int start = 0;
        int end = n-1;

        while (start <= end)
        {
            // int mid = (start + end)/ 2;
            int mid = start + (end - start) / 2 ;
            if(target > nums[mid]) {
                start = mid+1; // right
            }else if (target < nums[mid]){
                end = mid-1; // left
            }else {
                return mid;
            }
            
        }
        return -1;
    }
};