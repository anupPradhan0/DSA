

#include <iostream>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int addDigits(int num) {

//         while (num >= 10) {
//             int sum = 0;   // reset each round

//             while (num > 0) {
//                 sum += num % 10;
//                 num /= 10;
//             }

//             num = sum;
//         }

//         return num;  // return final single digit
//     }
// };

class Solution {
public:
    int addDigits(int num) {

        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    };
};

