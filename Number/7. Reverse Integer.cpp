

// 7. Reverse Integer

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


// class Solution {
// public:
//     int reverse(int x) {
//         int rev = 0;
//         while (x != 0) {
//             int pop = x % 10;
//             rev *= 10;
//             rev += pop;
//             x /= 10;
//         }
//         return rev;
//     }
// };


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            if(rev > INT_MAX/10 || (rev < INT_MIN / 10) ) {
                return 0;
            }
            rev *= 10;
            rev += pop;
            x /= 10;
        }
        return rev;
    }
};