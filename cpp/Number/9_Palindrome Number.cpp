
// 9. Palindrome Number
// Easy

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long reversedNumber = 0;
        int orig = x;
        while (x != 0) {
            int digit = x % 10;
            reversedNumber = reversedNumber * 10 + digit;
            x /= 10;
        }
        if(reversedNumber == orig) {
            return true;
        } else {
            return false;
        }
    }
};

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0) return false;
//         int reversedNumber = 0;
//         int orig = x;
//         while (x != 0) {
//             int digit = x % 10;
//             if (reversedNumber > (INT_MAX - digit) / 10) {
//                 return false; // would overflow, so not a palindrome
//             }
//             // ensures that reversedNumber * 10 + digit won't overflow.
//             //If it would, we return false immediately to avoid the crash.
//             reversedNumber = reversedNumber * 10 + digit;
//             x /= 10;
//         }
//         if(reversedNumber == orig) {
//             return true;
//         } else {
//             return false;
//         }
//     }
// };


int main() {
    Solution obj;
    int n = 121;
    cout << obj.isPalindrome(n) << endl;
}