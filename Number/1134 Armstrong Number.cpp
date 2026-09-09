

// 1134 Armstrong Number

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Armstrong {
public:
    bool isArmstrong(int n) {
        int org = n;
        int digits = 0;
        int temp = n;
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
        int sum = 0;
        while (n != 0) {
            int dig = 0;
            dig = n % 10;
            sum += pow(dig, digits);
            n /= 10;
        }
        return sum == org;
    }

};