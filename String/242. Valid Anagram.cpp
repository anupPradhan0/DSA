

// 242. Valid Anagram

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> char_counts;
        for (char c : s) {
            char_counts[c]++;
        }

        for (char c : t) {
            if (char_counts.find(c) == char_counts.end() || char_counts[c] == 0) {
                return false;
            }
            char_counts[c]--;
        }

        return true;
    }
};

