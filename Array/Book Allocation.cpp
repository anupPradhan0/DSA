
// Book Allocation
// on codechef
// Hard 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


bool isValid(vector<int> arr, int n, int m, int maxAllPages) { // O(N)
    int stu = 1;
    int pages = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] > maxAllPages) return false;

        if(pages + arr[i] <= maxAllPages) {
            pages += arr[i];
        } else {
            stu++;
            pages = arr[i];
        }
    }
    return stu > m ? false : true;
}

int allocateBook(vector<int> arr, int n , int m) { // O(logN * N)
    // edge casee
    if(m > n) return -1;
    // to cal the sum or the ending point 
    int sum = 0;
    for (int i = 0; i < n; i++) { // O(N)
        sum += arr[i];
    }
    // range of possible ans
    int st = 0;
    int end = sum;
    int ans = -1;
    while (st <= end){ // O(logN)
        int mid = st + (end - st) / 2;

        if(isValid(arr, n, m , mid)) { // left
            ans = mid;
            end = mid -1;
        } else { // right
            st = mid +1;
        }
    }
    return ans;
}

int main() {

    vector<int> arr = {2,1,3,4};
    int n = 4 , m = 2;

    cout<< allocateBook(arr, n, m) << endl;

}