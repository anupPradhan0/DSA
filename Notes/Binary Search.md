# 🔍 Binary Search - Complete C++ Study Guide

> **"The art of finding a needle in a haystack... efficiently!"**

## 📚 What is Binary Search?

Binary Search is like playing a **guessing game** where you're trying to guess someone's number between 1 and 100. The smart strategy? Always guess the middle number and eliminate half the possibilities with each guess!

### 🎯 Key Concept
- **Divide and Conquer**: Split the problem in half repeatedly
- **Only works on SORTED arrays** (this is crucial!)
- **Time Complexity**: O(log n) - incredibly fast!

---

## 🔧 Prerequisites

```
✅ Array must be SORTED
✅ Random access to elements (arrays/vectors work great)
✅ Comparable elements (numbers, strings, etc.)
```

---

## 🚀 Algorithm Walkthrough

### Visual Example
Let's find `target = 7` in `[1, 3, 5, 7, 9, 11, 13]`

```
Step 1: [1, 3, 5, 7, 9, 11, 13]
         ^     ^      ^
       start  mid    end
       mid = 7 ✅ FOUND!
```

### Another Example: Find `target = 5`
```
Step 1: [1, 3, 5, 7, 9, 11, 13]
         ^     ^      ^
       start  mid    end
       mid = 7 > 5, search left half

Step 2: [1, 3, 5] 7, 9, 11, 13
         ^  ^  ^
       start mid end
       mid = 3 < 5, search right half

Step 3: [1, 3, 5] 7, 9, 11, 13
            ^  ^
          start/mid/end
       mid = 5 ✅ FOUND!
```

---

## 💻 Implementation in C++

### 🔄 Iterative Version (Recommended)

```cpp
#include <vector>
#include <iostream>
using namespace std;

/**
 * Binary Search - Iterative Implementation
 * @param arr - Sorted vector
 * @param target - Value to find
 * @returns Index of target or -1 if not found
 */
int binarySearch(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start <= end) {
        // Avoid overflow: use this instead of (start + end) / 2
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            return mid; // Found it! 🎉
        } else if (arr[mid] < target) {
            start = mid + 1; // Search right half
        } else {
            end = mid - 1; // Search left half
        }
    }
    
    return -1; // Not found 😞
}

// Test function
void testBinarySearch() {
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    cout << "Testing Binary Search:" << endl;
    cout << "Search for 7: " << binarySearch(sortedArray, 7) << endl;  // Output: 3
    cout << "Search for 4: " << binarySearch(sortedArray, 4) << endl;  // Output: -1
    cout << "Search for 1: " << binarySearch(sortedArray, 1) << endl;  // Output: 0
    cout << "Search for 19: " << binarySearch(sortedArray, 19) << endl; // Output: 9
}
```

### 🔁 Recursive Version

```cpp
/**
 * Binary Search - Recursive Implementation
 * @param arr - Sorted vector
 * @param target - Value to find
 * @param start - Start index
 * @param end - End index
 * @returns Index of target or -1 if not found
 */
int binarySearchRecursive(vector<int>& arr, int target, int start, int end) {
    // Base case: search space exhausted
    if (start > end) {
        return -1;
    }
    
    int mid = start + (end - start) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, end);
    } else {
        return binarySearchRecursive(arr, target, start, mid - 1);
    }
}

// Wrapper function for easier use
int binarySearchRecursive(vector<int>& arr, int target) {
    return binarySearchRecursive(arr, target, 0, arr.size() - 1);
}

// Test function
void testBinarySearchRecursive() {
    vector<int> arr = {1, 3, 5, 7, 9};
    cout << "Recursive Binary Search for 5: " << binarySearchRecursive(arr, 5) << endl; // Output: 2
    cout << "Recursive Binary Search for 10: " << binarySearchRecursive(arr, 10) << endl; // Output: -1
}
```

---

## 🎯 Advanced Variations

### 1️⃣ Find Insert Position

```cpp
/**
 * Find the position where target should be inserted to keep array sorted
 * Also known as "Lower Bound"
 */
int searchInsertPosition(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    // Key insight: start points to the insert position!
    return start;
}

// Test function
void testSearchInsertPosition() {
    vector<int> arr = {1, 3, 5, 6};
    
    cout << "Insert Position Tests:" << endl;
    cout << "Target 5: " << searchInsertPosition(arr, 5) << endl; // 2 (found)
    cout << "Target 2: " << searchInsertPosition(arr, 2) << endl; // 1 (insert here)
    cout << "Target 7: " << searchInsertPosition(arr, 7) << endl; // 4 (end of array)
    cout << "Target 0: " << searchInsertPosition(arr, 0) << endl; // 0 (beginning)
}
```

### 2️⃣ Find First Occurrence

```cpp
/**
 * Find the first occurrence of target in array with duplicates
 */
int findFirstOccurrence(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int result = -1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            end = mid - 1; // Keep searching left for first occurrence
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return result;
}

// Test function
void testFindFirstOccurrence() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    cout << "First occurrence of 2: " << findFirstOccurrence(arr, 2) << endl; // Output: 1
    cout << "First occurrence of 6: " << findFirstOccurrence(arr, 6) << endl; // Output: -1
}
```

### 3️⃣ Find Last Occurrence

```cpp
/**
 * Find the last occurrence of target in array with duplicates
 */
int findLastOccurrence(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    int result = -1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            start = mid + 1; // Keep searching right for last occurrence
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return result;
}

// Test function
void testFindLastOccurrence() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    cout << "Last occurrence of 2: " << findLastOccurrence(arr, 2) << endl; // Output: 3
    cout << "Last occurrence of 1: " << findLastOccurrence(arr, 1) << endl; // Output: 0
}
```

### 4️⃣ Count Occurrences

```cpp
/**
 * Count total occurrences of target using first and last occurrence
 */
int countOccurrences(vector<int>& arr, int target) {
    int first = findFirstOccurrence(arr, target);
    if (first == -1) return 0; // Element not found
    
    int last = findLastOccurrence(arr, target);
    return last - first + 1;
}

// Test function
void testCountOccurrences() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    cout << "Count of 2: " << countOccurrences(arr, 2) << endl; // Output: 3
    cout << "Count of 1: " << countOccurrences(arr, 1) << endl; // Output: 1
    cout << "Count of 6: " << countOccurrences(arr, 6) << endl; // Output: 0
}
```

### 5️⃣ Search in Rotated Sorted Array

```cpp
/**
 * Search in rotated sorted array
 * Example: [4,5,6,7,0,1,2] rotated at index 4
 */
int searchRotatedArray(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        // Check which half is sorted
        if (arr[start] <= arr[mid]) { // Left half is sorted
            if (target >= arr[start] && target < arr[mid]) {
                end = mid - 1; // Target is in left half
            } else {
                start = mid + 1; // Target is in right half
            }
        } else { // Right half is sorted
            if (target > arr[mid] && target <= arr[end]) {
                start = mid + 1; // Target is in right half
            } else {
                end = mid - 1; // Target is in left half
            }
        }
    }
    
    return -1;
}

// Test function
void testSearchRotatedArray() {
    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    cout << "Search 0 in rotated array: " << searchRotatedArray(rotated, 0) << endl; // Output: 4
    cout << "Search 3 in rotated array: " << searchRotatedArray(rotated, 3) << endl; // Output: -1
}
```

---

## 📊 Complexity Analysis

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time (Best Case)** | O(1) | Target found at middle on first try |
| **Time (Average/Worst)** | O(log n) | Eliminate half each time |
| **Space (Iterative)** | O(1) | Only using a few variables |
| **Space (Recursive)** | O(log n) | Call stack depth |

### 🤔 Why O(log n)?
With each comparison, we eliminate half the remaining elements:
- n → n/2 → n/4 → n/8 → ... → 1
- Number of steps = log₂(n)

---

## 🎯 Pro Tips & Common Pitfalls

### ✅ Do's
```cpp
// ✅ Correct way to calculate mid (avoids overflow)
int mid = start + (end - start) / 2;

// ✅ Use <= in while condition
while (start <= end) { ... }

// ✅ Always verify array is sorted first
bool isSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

// ✅ Handle edge cases
if (arr.empty()) return -1;
```

### ❌ Don'ts
```cpp
// ❌ Can cause overflow for large numbers
int mid = (start + end) / 2;

// ❌ Missing = will cause infinite loops
while (start < end) { ... }

// ❌ Forgetting to check if array is sorted
// Binary search only works on sorted arrays!

// ❌ Not handling empty arrays
// Always check if vector is empty first
```

---

## 🧪 Interactive Practice & Real-World Applications

### Test Your Understanding
```cpp
void practiceProblems() {
    vector<int> mystery = {2, 5, 8, 12, 16, 23, 38, 45, 67, 78, 89, 99};
    
    cout << "=== PRACTICE PROBLEMS ===" << endl;
    cout << "Array: [2, 5, 8, 12, 16, 23, 38, 45, 67, 78, 89, 99]" << endl << endl;
    
    // Challenge: Can you trace through these step by step?
    cout << "Search for 23: " << binarySearch(mystery, 23) << endl;  // What will this return?
    cout << "Search for 1: " << binarySearch(mystery, 1) << endl;    // ?
    cout << "Search for 99: " << binarySearch(mystery, 99) << endl;  // ?
    cout << "Search for 50: " << binarySearch(mystery, 50) << endl;  // ?
}
```

### Real-World Applications

#### 1️⃣ **Square Root Approximation**
```cpp
/**
 * Find square root using binary search
 * Time: O(log n), Space: O(1)
 */
double findSquareRoot(double n, double precision = 0.001) {
    if (n < 0) return -1; // Invalid input
    if (n == 0 || n == 1) return n;
    
    double start = 0;
    double end = n;
    
    // For numbers less than 1, search between n and 1
    if (n < 1) {
        start = n;
        end = 1;
    }
    
    while (end - start > precision) {
        double mid = start + (end - start) / 2;
        double square = mid * mid;
        
        if (square > n) {
            end = mid;
        } else {
            start = mid;
        }
    }
    
    return (start + end) / 2;
}

// Test function
void testSquareRoot() {
    cout << "Square root of 25: " << findSquareRoot(25) << endl;     // ≈ 5.0
    cout << "Square root of 2: " << findSquareRoot(2) << endl;      // ≈ 1.414
    cout << "Square root of 0.25: " << findSquareRoot(0.25) << endl; // ≈ 0.5
}
```

#### 2️⃣ **Peak Element Finder**
```cpp
/**
 * Find a peak element in array (element greater than its neighbors)
 * Works even in unsorted arrays!
 */
int findPeakElement(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start < end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] > arr[mid + 1]) {
            // Peak is in left half (including mid)
            end = mid;
        } else {
            // Peak is in right half
            start = mid + 1;
        }
    }
    
    return start; // start == end, pointing to peak
}

// Test function
void testFindPeak() {
    vector<int> arr1 = {1, 2, 3, 1};
    vector<int> arr2 = {1, 2, 1, 3, 5, 6, 4};
    
    cout << "Peak in [1,2,3,1]: " << findPeakElement(arr1) << endl;     // 2 (index of element 3)
    cout << "Peak in [1,2,1,3,5,6,4]: " << findPeakElement(arr2) << endl; // 1 or 5 (multiple peaks possible)
}
```

#### 3️⃣ **STL Binary Search Functions**
```cpp
void demonstrateSTLBinarySearch() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 6};
    
    cout << "=== STL BINARY SEARCH FUNCTIONS ===" << endl;
    
    // binary_search: Check if element exists
    cout << "Does 4 exist? " << binary_search(arr.begin(), arr.end(), 4) << endl; // true
    
    // lower_bound: First position where element can be inserted
    auto lower = lower_bound(arr.begin(), arr.end(), 4);
    cout << "Lower bound of 4: " << (lower - arr.begin()) << endl; // Index 4
    
    // upper_bound: Last position where element can be inserted
    auto upper = upper_bound(arr.begin(), arr.end(), 4);
    cout << "Upper bound of 4: " << (upper - arr.begin()) << endl; // Index 7
    
    // Count occurrences using STL
    cout << "Count of 4: " << (upper - lower) << endl; // 3
    
    // equal_range: Get both bounds at once
    auto range = equal_range(arr.begin(), arr.end(), 4);
    cout << "Equal range of 4: [" << (range.first - arr.begin()) 
         << ", " << (range.second - arr.begin()) << ")" << endl; // [4, 7)
}
```

---

## 🎨 Template Variations

### 🔍 **Generic Binary Search Template**
```cpp
template<typename T>
int binarySearch(vector<T>& arr, T target) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return -1;
}
```

### 🎯 **Binary Search with Custom Comparator**
```cpp
template<typename T, typename Compare>
int binarySearchWithComparator(vector<T>& arr, T target, Compare comp) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (!comp(arr[mid], target) && !comp(target, arr[mid])) {
            return mid; // Elements are equal
        } else if (comp(arr[mid], target)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return -1;
}

// Example usage with strings (case-insensitive)
void testCustomComparator() {
    vector<string> words = {"apple", "banana", "cherry", "date"};
    
    auto caseInsensitiveComp = [](const string& a, const string& b) {
        string lowerA = a, lowerB = b;
        transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA < lowerB;
    };
    
    cout << "Search 'BANANA': " << binarySearchWithComparator(words, string("BANANA"), caseInsensitiveComp) << endl;
}
```

---

## 🏆 Complete Test Suite

```cpp
// Complete main function to test all implementations
int main() {
    cout << "=== BINARY SEARCH COMPLETE DEMO ===" << endl << endl;
    
    // Basic binary search tests
    testBinarySearch();
    cout << endl;
    
    // Recursive version test
    testBinarySearchRecursive();
    cout << endl;
    
    // Advanced variations
    testSearchInsertPosition();
    cout << endl;
    
    testFindFirstOccurrence();
    cout << endl;
    
    testFindLastOccurrence();
    cout << endl;
    
    testCountOccurrences();
    cout << endl;
    
    testSearchRotatedArray();
    cout << endl;
    
    // Practice problems
    practiceProblems();
    cout << endl;
    
    // Real-world applications
    testSquareRoot();
    cout << endl;
    
    testFindPeak();
    cout << endl;
    
    // STL functions demo
    demonstrateSTLBinarySearch();
    cout << endl;
    
    return 0;
}
```

---

## 🎯 Summary

Binary Search is your **secret weapon** for:
- ⚡ **Lightning-fast searches** in sorted data (O(log n))
- 🎯 **Finding insert positions** for maintaining sorted order  
- 🔍 **Locating boundaries** and ranges in datasets
- 💡 **Solving optimization problems** with "search the answer"

**Remember the mantra**: *"If it's sorted, think Binary Search!"*

---

## 📝 Quick Reference

```cpp
// Basic Template
int binarySearch(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    
    return -1; // Not found
}

// Key Points:
// 1. Array MUST be sorted
// 2. Use start + (end - start) / 2 to avoid overflow
// 3. Use <= in while condition
// 4. Handle edge cases (empty array, single element)
```

**Happy Searching! 🚀**