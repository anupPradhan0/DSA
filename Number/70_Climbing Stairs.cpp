
// 70. Climbing Stairs 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;



class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;

        int num1 = 1;
        int num2 = 1;
        int curr = 0;

        for (int i = 2; i <= n; i++) {
            curr = num1 + num2;
            num2 = num1;
            num1 = curr;
        }
        return curr;
    }
};


int countWays(int n) {
    if (n == 0 || n == 1) return 1;

    int prev1 = 1; // ways to reach step 1
    int prev2 = 1; // ways to reach step 0
    int curr = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        cout << curr << endl;
    }
    return curr;
}

int main() {
    cout << countWays(10) << endl;
}