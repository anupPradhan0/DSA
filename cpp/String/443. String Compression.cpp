

// 443. String Compression

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int compress(vector<char>& ch) {
        int idx = 0;
        for (int i = 0; i < ch.size();) {
            int count = 0;
            char curr = ch[i];
            while (i < ch.size() && ch[i] == curr) {
                count++;
                i++;
            }
            if(count == 1) {
                ch[idx++] = curr;
            } else {
                ch[idx++] = curr;
                for( char c : to_string(count)) {
                    ch[idx++] = c;
                }
            }
            
        }
        return idx;
    }
};