

// 31. Next Permutation

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        // find the pivot
        int n = arr.size();
        int piv = -1;
        for(int i = n-2; i>= 0;i--) {
            if(arr[i] < arr[i+1]) {
                piv = i;
                break;
            }
        }
        if(piv == -1) {
            reverse(arr.begin(), arr.end()); // in place changes
            return;
        }
        // 2nd : Next larger element
        for (int i =n-1; i > piv; i--) {
            if(arr[i] > arr[piv]) {
                swap(arr[i], arr[piv]);
                break;
            }
        }
        // 3rd : reverse pivot to n
        // reverse(arr.begin() + piv+1, arr.end());
        int i = piv+1; 
        int j = n-1;
        while (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};