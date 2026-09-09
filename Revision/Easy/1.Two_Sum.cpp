#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) { 
        int n = size(arr);
        for ( int i  = 0; i < n; i++) {
            for ( int j = i +1; j < n; j++) {
                if ( arr[i] + arr[j] == target) {
                    return {i, j};
                };
            }
        }
        return {};
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solution.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found" << endl;
    }
    
    return 0;
}

