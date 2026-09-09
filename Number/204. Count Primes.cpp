
// 204. Count Primes

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        int ans = 0;
        vector<bool> isPrime(n+1 , true);
        for (int i = 2; i < n; i++) {
            if(isPrime[i]) {
                ans++;
                for(int j = i*2; j < n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        return ans;
    }
};