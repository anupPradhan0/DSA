
// 1572. Matrix Diagonal Sum



// Diagonal Sum 
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

// int diagonalSum(vector<vector<int>>& mat) {
//     int sum = 0;
//     int n = mat.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if(i == j) {
//                 sum += mat[i][j];
//             } else if(j == n - 1 - i) {
//                 sum += mat[i][j];
//             }
//         }
//     }
//     return sum;
// }

int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        sum += mat[i][i];
        if(i != n - 1 - i) {
            sum += mat[i][n-1-i];
        }
    }
    return sum;
}


int main () {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << diagonalSum(matrix) << endl;

}