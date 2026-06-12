// 912. Sort an Array

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] >= arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 2, 3, 1};
    sol.sortArray(arr);
    for (int i : arr)
        cout << i << " ";
    return 0;
}

class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] >= arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        return arr;
    }
};