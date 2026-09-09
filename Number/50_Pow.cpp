#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// class Solution {
// public:
//     double myPow(double x, int n) {
        
//         if(n == 0) return 1.0;
//         if(x == 0) return 0.0;
//         if(x == 1) return 1.0;
//         if(x == -1 && n%2 == 0) return 1.0;
//         if(x == -1 && n%2 != 0) return -1.0;

//         long binForm = n;

//         if(binForm < 0) {
//             x = 1/x;
//             binForm = -binForm;
//         }

//         double ans = 1;

//         while (binForm > 0)
//         {
//             if(binForm % 2 == 1) {
//                 ans *=x;
//             }
//             x *= x;
//             binForm /= 2;
//         }
//         return ans;
//     }
// };



double myPow(double x, int n) {

    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && n%2 == 0) return 1.0;
    if(x == -1 && n%2 != 0) return -1.0;

    long bin = n;

    if(bin < 0) {
        x = 1/x;
        bin = -bin;
    }
    
    double ans = 1;

    while (bin > 0)
    {
        if(bin % 2 == 1) {
            ans *= x;
        }
        x *= x;
        bin /= 2;
    }
    return ans;
}

int main() {
    double x = 2;
    int n = 5;

    double result = myPow(x, n);
    cout << "2^5 = " << result << endl;  // Output: 32
    return 0;
}