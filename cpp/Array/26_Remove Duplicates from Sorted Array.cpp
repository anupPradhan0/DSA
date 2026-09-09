#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& num) {

        int n = num.size();
        int val = 0;
        for (int i = 0; i < n; i++) {
            if(num[val] != num[i]) {
                num[++val] = num[i];
            }
        }
        return val+1;
    }
};