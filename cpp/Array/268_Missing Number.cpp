

// 268. Missing Number


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int currentSum = 0;
        for(int val : arr) {
            currentSum += val;
        }
        int supposeSum = n * (n+1) / 2;

        return supposeSum - currentSum;
    }
};

