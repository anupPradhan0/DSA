

// 540. Single Element in a Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& arr) {

//         int n = arr.size();

//         for (int i = 1; i < n; i++) {
//             if (arr[i-1] != arr[i] && arr[i] != arr[i+1])
//             if(arr[i-1] != arr[i] && arr[i] != arr[i+1]) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {

        int n = arr.size();
        if(n == 1) return arr[0];
        int st = 0;
        int end = n-1;

        while ( st <= end ) {

            int mid =  st + ( end - st ) / 2;

            if(mid == 0 && arr[0] != arr[1]) return arr[mid] ;
            if(mid == n-1 && arr[n-1] != arr[n-2]) return arr[mid] ;

            if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) return arr[mid];


            if(mid % 2 == 0) {
                if(arr[mid-1] == arr[mid]) {
                    end = mid -1;
                } else {
                    st = mid +1;
                }
            } else {
                if(arr[mid-1] == arr[mid]) {
                    st = mid +1;
                } else {
                    end = mid -1;
                }
            }
        }
        return -1;
    }
};