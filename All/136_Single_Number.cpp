#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = size(arr);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n ; j++) {
                if (arr[i] = arr[j]) {
                    return arr[i];
                }
            }
        }
        return 0; 
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2,2,1};
    cout << "Example 1: Input: [2,2,1]" << endl;
    cout << "Output: " << sol.singleNumber(nums1) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Example 2
    vector<int> nums2 = {4,1,2,1,2};
    cout << "Example 2: Input: [4,1,2,1,2]" << endl;
    cout << "Output: " << sol.singleNumber(nums2) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Example 3
    vector<int> nums3 = {1};
    cout << "Example 3: Input: [1]" << endl;
    cout << "Output: " << sol.singleNumber(nums3) << endl;
    cout << "Expected: 1" << endl;
    
    return 0;
}

