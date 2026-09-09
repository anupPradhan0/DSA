
// 18. 4Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

// arr = [1,0,-1,0,-2,2], target = 0
// Brute 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) { // O(n4⋅logm) time
        int n = arr.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    for (int l = k+1; l < n; l++) {
                        if (arr[i] + arr[j] + arr[k] + arr[l] == target) { // O(m) space
                            vector<int> sum = {arr[i] , arr[j] , arr[k] , arr[l]};
                            sort(sum.begin(), sum.end());

                            if (s.find(sum) == s.end()) {
                                s.insert(sum);
                                ans.push_back(sum);
                            }
                        }
                    }
                }
            }

        }
        
        return ans;
    }
};

// arr = [1,0,-1,0,-2,2], target = 0
// 2 pointer
// Better Approach
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i-1]) continue; 

            for (int j = i+1; j < n; j++) {
                if (j > i+1 && arr[j] == arr[j-1]) continue;

                int st = j+1, end = n-1;
                while (st < end) {
                    long long sum = (long long)arr[i] + arr[j] + arr[st] + arr[end];
                    if (sum < target) st++;
                    else if (sum > target) end--;
                    else {
                        ans.push_back({arr[i], arr[j], arr[st], arr[end]});
                        st++, end--;

                        while (st < end && arr[st] == arr[st-1]) st++;
                        while (st < end && arr[end] == arr[end+1]) end--;
                    }
                }
            }
        }
        return ans;
    }
};
