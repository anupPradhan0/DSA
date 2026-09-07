// 66. Plus One

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        long num = 0;
        if (arr.back() < 9 ) {
            arr.push_back(arr.back() + 1);
            return arr;
        }
        for (int digit : arr) {
            num = num * 10 +digit;
        }
        num +=1;
        arr.clear();
        while (num > 0) {
            arr.push_back(num % 10);
            num /=10;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        if ( arr.back() < 9 ) {
            arr.back()++;
            return arr;
        };
        int i = arr.size() - 1;

        while (i >= 0 && arr[i] == 9) {
            arr[i] = 0;
            i--;
        }
        if (i >= 0) {
            arr[i]++;
        } else {
            arr.insert(arr.begin(), 1);
        }
        return arr;
    }
};