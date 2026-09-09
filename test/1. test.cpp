
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i=0; i<n; i++) {
            int fir = arr[i];
            int sec = target - fir;

            if (map.find(sec) != map.end()) {
                ans.push_back(i);
                ans.push_back(map[sec]);
                break;
            }
            map[fir] = i;
        }
        return ans;
    }
};