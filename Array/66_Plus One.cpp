// 66. Plus One

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// class Solution {
// public:
//     vector<int> plusOne(vector<int>& arr) {

//         long num = 0;
//         for(int val : arr){
//             num = num * 10 + val;
//         }
//         num += 1;
        
//         arr.clear();

//         while (num > 0) {
//             arr.push_back(num % 10);
//             num /= 10 ;
//         }
//         reverse(arr.begin(), arr.end());
//         return arr;
//     }
// };


class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {

        int n = arr.size();

        for (int i = n - 1; i >= 0; i--) {

            if(arr[i] < 9) {
                arr[i] += 1;
                return arr;
            } else {
                arr[i] = 0;
            }

        }
        
        arr.insert(arr.begin() , 1);
        return arr;
    }
};





int main() {
    Solution sol;
    vector<int> digits = {8, 9, 9};
    vector<int> result = sol.plusOne(digits);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}