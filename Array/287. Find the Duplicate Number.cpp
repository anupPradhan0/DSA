
// 287. Find the Duplicate Number

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

// taking too much memory
class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        unordered_set<int> s;
        for (int val : arr) {
            if (s.find(val) != s.end()) {
                return val;
            }
            s.insert(val);
        }
        return -1;
    }
};


// link list
class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];

        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        
        slow = arr[0];

        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
    }
};