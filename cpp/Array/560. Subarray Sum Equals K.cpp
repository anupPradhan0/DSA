

// 560. Subarray Sum Equals K

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;


// Input: arr = [1,1,1], k = 2
// Output: 2
// Brute-Better
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) ans++;
            }
            
        }

        return ans;
    }
};

// Input: arr = [1,1,1], k = 2
// Output: 2
// Optimal approach // Prefix sum
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }

        unordered_map<int, int> m;
        for (int j = 0; j < n; j++) {
            if (prefix[j] == k) count++;

            int val = prefix[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }

            if (m.find(prefix[j]) == m.end()) {
                m[prefix[j]] = 0;

            }
            m[prefix[j]]++;
        }
        return count;
    }
};

