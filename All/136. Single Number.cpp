#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = size(arr);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && arr[i] == arr[j]) {
                    break;
                }
                if (j == n - 1) {
                    return arr[i];
                }
            }
        }
        return -1; // This line should never be reached if input is valid
    }
};


class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans = 0;
        for (int val : arr) {
            ans ^= val; 
        
        }
        return ans;
    }
};


class Soluction {
public:
    int singleNumber(vector<int>& arr) {
        int n =  size(arr);
        for (int i = 0; i <= n; i++) {
            
        }
    }
}