

// 2965. Find Missing and Repeated Values

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int> s;
        int n = grid.size();
        int a, b;
        int expSum= 0, actSum= 0;

        for (int i = 0; i < n; i++) {
            for(int j=0; j<n; j++) {
                actSum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expSum = (n*n) * (n*n +1) / 2;
        b = expSum + a - actSum;
        ans.push_back(b);
        return ans;
    }
};