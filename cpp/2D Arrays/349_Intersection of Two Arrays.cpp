

// 349. Intersection of Two Arrays


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;



class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;

        for(int val1 : arr1) {
            for(int val2 : arr2) {
                if(val1 == val2) {
                    ans.push_back(val1);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
