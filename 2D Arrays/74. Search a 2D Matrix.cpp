
// 74. Search a 2D Matrix

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// [[1,3]] not able to solve this 
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& mat, int target) {
//         int n = mat.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] == target) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// 0(N(m * n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

//  O(log(m * n))
class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == mat[row][mid]) {
                return true;
            } else if (target > mat[row][mid]){
                st = mid +1;
            } else {
                end = mid -1;
            }
        }
        return false;
    };

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int startRow = 0, endRow = m -1;
        while (startRow <= endRow ) {
            int midRow = startRow + (endRow - startRow) / 2;

            if(mat[midRow][0] <= target && target <= mat[midRow][n-1]) {
                // find in middle row
                return searchInRow(mat, target, midRow);
            } else if (target >= mat[midRow][n-1]) {
                // down  => Right
                startRow = midRow +1;
            } else {
                // uper => left
                endRow = midRow -1;
            }
        }
        return false;
    }
};