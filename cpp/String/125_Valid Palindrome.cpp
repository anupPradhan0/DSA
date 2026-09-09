

// 125. Valid Palindrome

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// class Solution {
// public:
//     bool isPalindrome(string s) {

//         // Step 1: Clean the string
//         string orig = "";
//         // Filter only alphanumeric and lowercase everything
//         for (char c : s) {
//             if (isalnum(c)) {
//                 orig += tolower(c);
//             }
//         }

//         // Step 2: Check if the cleaned string is a palindrome
//         reverse(orig.begin(), orig.end());
//         string reverseString = orig;
//         reverse(orig.begin(), orig.end());
//         if(orig == reverseString) {
//             return true;
//         }
//         return false;
//     }
// };



// class Solution {
// public:
//     bool isPalindrome(string s) {
//         // Step 1: Clean the string
//         string orig = "";
//         // Filter only alphanumeric and lowercase everything
//         for (char c : s) {
//             if (isalnum(c)) {
//                 orig += tolower(c);
//             }
//         }

//         int start = 0;
//         int end = orig.size() -1;
//         while (start < end) {
//             if(orig[start] == orig[end]){
//                 start++;
//                 end--;
//             } else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isPalindrome(string s) {

        int start = 0;
        int end = s.size() -1;
        while (start < end) {

            if(!isalnum(s[start])){
                start++;
                continue;
            } if(!isalnum(s[end])) {
                end--;
                continue;
            }

            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};