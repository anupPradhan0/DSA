

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {

        int n = x;
        if ( n < 0) return false;
        long long orig = n, rev = 0;

        while (n != 0){
            rev = rev * 10 + (n%10);
            n/= 10;
        };
        return rev == orig;
    }
};


