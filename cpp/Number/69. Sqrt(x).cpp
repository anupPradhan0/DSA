

// 69. Sqrt(x)

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// brute-force
class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        for (long long i = 1; i * i <= x; i++) {
            ans = i;
        };
        return ans;
    }
};



// Binary Search

class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int ans =0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long sq = (long long)mid * mid;
            if (sq == x) {
                ans = mid;
                break;
            } else if (sq < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            };
        };
        return ans;
    }
};

