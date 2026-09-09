

// 15. 3Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Brute 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        vector<int> triplet = {arr[i], arr[j], arr[k]};
                        sort(triplet.begin(), triplet.end());

                        if (s.find(triplet) == s.end()) {
                            s.insert(triplet);
                            ans.push_back(triplet);
                        }
                    }
                }
            }
        }

        return ans;
    }
};


// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Better
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        set<vector<int>> uniqT;

        for (int i=0; i<n; i++) {
            int tar = -arr[i];
            set<int> s;

            for (int j=i+1; j<n; j++) {
                int third = tar - arr[j];

                if (s.find(third) != s.end()) {
                    vector<int> trip = {arr[i], arr[j], third};
                    sort(trip.begin(), trip.end());
                    uniqT.insert(trip);
                };

                s.insert(arr[j]);
            }
        }
        vector<vector<int>> ans(uniqT.begin(), uniqT.end());
        return ans;
    }
};

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Optimized
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for (int i=0; i<n; i++) {

            if (i > 0 && arr[i] == arr[i-1]) continue;

            int st = i+1;
            int end = n-1;

            while (st < end) {
                int sum = arr[i] + arr[st] + arr[end];
                if (sum < 0) st++;
                else if (sum > 0) end--;
                else {
                    ans.push_back({ arr[i], arr[st], arr[end] });
                    st++, end--;
                    while (st < end && arr[st] == arr[st-1]) st++;
                    while (st < end && arr[end] == arr[end+1]) end--;
                }
            }
        }
        return ans;
    }
};
