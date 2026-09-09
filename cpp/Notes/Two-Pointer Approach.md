# 👥 Two-Pointer Technique - Complete C++ Study Guide

> **"Two is better than one - especially when solving array problems!"**

## 🎯 What is the Two-Pointer Technique?

Imagine you have two friends helping you search through a bookshelf. Instead of checking every book one by one, they work together strategically - one starts from the left, one from the right, and they meet in the middle. That's the essence of the two-pointer technique!

### 🔑 Core Concept
- **Two pointers** traverse a data structure simultaneously
- **Reduces O(n²) brute force** to **O(n)** linear time
- **Smart collaboration** between pointers to solve problems efficiently

---

## 🎨 Types of Two-Pointer Patterns

### 1️⃣ **Opposite Ends Pattern** (Convergent Pointers)

```
Visual: [1, 2, 3, 4, 5, 6, 7, 8, 9]
         ↑                       ↑
       left                   right
         
Step 1:  ←------- meet -------→
Step 2:    ←----- here ----→
Step 3:      ←--- 🤝 ---→
```

**Perfect for:**
- 🔄 Palindrome checking
- 🎯 Two Sum in sorted arrays
- 💧 Container with most water
- ⚖️ Pair comparisons

### 2️⃣ **Same Direction Pattern** (Sliding Window)

```
Visual: [1, 2, 3, 4, 5, 6, 7, 8, 9]
         ↑  ↑
      slow fast
         
Step 1:  →→→→→ (fast moves)
Step 2:  → →→→→ (slow catches up)
Step 3:    →→→→→ (window slides)
```

**Perfect for:**
- 🪟 Sliding window problems
- 📊 Subarray sums
- 🗑️ Remove duplicates
- 🎚️ Variable-length sequences

---

## 💻 Implementation Patterns in C++

### 🔄 Pattern 1: Opposite Ends Template

```cpp
#include <vector>
#include <iostream>
using namespace std;

/**
 * Template for Opposite Ends Two-Pointer Pattern
 */
vector<pair<int, int>> oppositeEndsTemplate(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    vector<pair<int, int>> result;
    
    while (left < right) {
        // Process current pair
        int currentSum = arr[left] + arr[right];
        
        // Make decision based on your problem
        if (currentSum == target) {
            // Found what we're looking for!
            result.push_back({left, right});
            left++;
            right--;
        } else if (currentSum < target) {
            left++; // Need larger sum
        } else {
            right--; // Need smaller sum
        }
    }
    
    return result;
}
```

### 🪟 Pattern 2: Same Direction Template

```cpp
/**
 * Template for Same Direction Two-Pointer Pattern (Sliding Window)
 */
int sameDirctionTemplate(vector<int>& arr, int target) {
    int left = 0;
    int right = 0;
    int windowSum = 0;
    int maxLength = 0;
    
    while (right < arr.size()) {
        // Expand window by including arr[right]
        windowSum += arr[right];
        
        // Shrink window if needed
        while (windowSum > target && left <= right) {
            windowSum -= arr[left];
            left++;
        }
        
        // Update result with current valid window
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    
    return maxLength;
}
```

---

## 🚀 Real Problem Solutions

### 1️⃣ **Palindrome Checker**

```cpp
#include <string>
#include <algorithm>
#include <cctype>

/**
 * Check if a string is a palindrome using two pointers
 * Time: O(n), Space: O(1)
 */
bool isPalindrome(string s) {
    // Clean the string: remove non-alphanumeric and convert to lowercase
    string cleaned = "";
    for (char c : s) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    
    int left = 0;
    int right = cleaned.length() - 1;
    
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false; // Not a palindrome!
        }
        left++;
        right--;
    }
    
    return true; // It's a palindrome! 🎉
}

// Test function
void testPalindrome() {
    cout << "Testing Palindromes:" << endl;
    cout << isPalindrome("A man a plan a canal Panama") << endl; // 1 (true)
    cout << isPalindrome("race a car") << endl; // 0 (false)
    cout << isPalindrome("Was it a car or a cat I saw?") << endl; // 1 (true)
}

/**
 * Visual trace for "racecar":
 * Step 1: r a c e c a r
 *         ↑           ↑  (r === r ✓)
 * Step 2: r a c e c a r  
 *           ↑       ↑    (a === a ✓)
 * Step 3: r a c e c a r
 *             ↑   ↑      (c === c ✓)
 * Step 4: r a c e c a r
 *               ↑        (left >= right, DONE!)
 */
```

### 2️⃣ **Two Sum in Sorted Array**

```cpp
/**
 * Find two numbers that add up to target in a sorted array
 * Time: O(n), Space: O(1)
 */
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int currentSum = nums[left] + nums[right];
        
        if (currentSum == target) {
            return {left, right}; // Found the pair! 🎯
        } else if (currentSum < target) {
            left++; // Need a larger sum, move left pointer right
        } else {
            right--; // Need a smaller sum, move right pointer left
        }
    }
    
    return {-1, -1}; // No solution found
}

// Test function
void testTwoSum() {
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> result1 = twoSumSorted(nums1, 9);
    cout << "Two Sum Result: [" << result1[0] << ", " << result1[1] << "]" << endl; // [0, 1]
    
    vector<int> nums2 = {1, 2, 3, 4, 6};
    vector<int> result2 = twoSumSorted(nums2, 6);
    cout << "Two Sum Result: [" << result2[0] << ", " << result2[1] << "]" << endl; // [1, 3]
}

/**
 * Visual trace for [2, 7, 11, 15], target = 9:
 * Step 1: [2, 7, 11, 15]
 *          ↑          ↑   sum = 17 > 9, move right left
 * Step 2: [2, 7, 11, 15]
 *          ↑      ↑       sum = 13 > 9, move right left  
 * Step 3: [2, 7, 11, 15]
 *          ↑   ↑          sum = 9 === 9, FOUND! 🎉
 */
```

### 3️⃣ **Container With Most Water**

```cpp
/**
 * Find the container that can hold the most water
 * Time: O(n), Space: O(1)
 */
int maxWaterContainer(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
    int maxWater = 0;
    
    while (left < right) {
        // Calculate current water area
        int width = right - left;
        int height = min(heights[left], heights[right]);
        int currentWater = width * height;
        
        // Update maximum water
        maxWater = max(maxWater, currentWater);
        
        // Move the pointer with smaller height
        // (moving the taller one won't help!)
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;
}

// Test function
void testWaterContainer() {
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << "Max Water Container: " << maxWaterContainer(heights) << endl; // Output: 49
}

/**
 * Visual representation:
 * Heights: [1, 8, 6, 2, 5, 4, 8, 3, 7]
 * Indices:  0  1  2  3  4  5  6  7  8
 * 
 * Container between index 1 and 8:
 * Width = 8 - 1 = 7
 * Height = min(8, 7) = 7  
 * Area = 7 × 7 = 49 💧
 */
```

### 4️⃣ **Remove Duplicates In-Place**

```cpp
/**
 * Remove duplicates from sorted array in-place
 * Time: O(n), Space: O(1)
 */
int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    
    int slow = 0; // Points to last unique element
    
    for (int fast = 1; fast < nums.size(); fast++) {
        // Found a new unique element
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast]; // Place it next to other uniques
        }
    }
    
    return slow + 1; // Length of unique elements
}

// Test function
void testRemoveDuplicates() {
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int newLength = removeDuplicates(arr);
    
    cout << "After removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Output: 1 2 3 4 5
}

/**
 * Visual trace for [1, 1, 2, 2, 2, 3]:
 * 
 * Initial: [1, 1, 2, 2, 2, 3]
 *           s  f              (1 === 1, fast++)
 * 
 * Step 1:  [1, 1, 2, 2, 2, 3]
 *           s     f           (1 !== 2, found new unique!)
 * 
 * Result:  [1, 2, 2, 2, 2, 3]
 *              s  f           (slow++, nums[slow] = nums[fast])
 */
```

### 5️⃣ **Three Sum Problem**

```cpp
/**
 * Find all unique triplets that sum to zero
 * Time: O(n²), Space: O(1) excluding output
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sort first!
    
    for (int i = 0; i < nums.size() - 2; i++) {
        // Skip duplicates for first element
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int left = i + 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

// Test function
void testThreeSum() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    cout << "Three Sum Results:" << endl;
    for (auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    // Output: [-1, -1, 2] and [-1, 0, 1]
}
```

### 6️⃣ **Move Zeros to End**

```cpp
/**
 * Move all zeros to the end while maintaining relative order
 * Time: O(n), Space: O(1)
 */
void moveZeros(vector<int>& nums) {
    int slow = 0; // Position for next non-zero element
    
    // Move all non-zero elements to the front
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    
    // Fill remaining positions with zeros
    while (slow < nums.size()) {
        nums[slow] = 0;
        slow++;
    }
}

// Alternative: Swap version (maintains relative order better)
void moveZerosSwap(vector<int>& nums) {
    int slow = 0;
    
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

// Test function
void testMoveZeros() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeros(nums);
    
    cout << "After moving zeros: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 3 12 0 0
}
```

---

## 📊 Complexity Analysis

| Problem Type | Time Complexity | Space Complexity | Notes |
|--------------|----------------|------------------|--------|
| **Opposite Ends** | O(n) | O(1) | Linear scan, constant space |
| **Same Direction** | O(n) | O(1) | Each element visited at most twice |
| **Three Sum** | O(n²) | O(1) | Nested loops with two-pointer |
| **Palindrome Check** | O(n) | O(1) | Single pass comparison |

### 🤔 Why Two-Pointer is Efficient?
- **Eliminates nested loops**: Instead of checking all pairs O(n²), we intelligently move pointers
- **Leverages sorted property**: In sorted arrays, we can make informed decisions about pointer movement
- **Constant space**: Usually only uses a few extra variables

---

## 🎯 Problem-Solving Strategy

### 🔍 **Step-by-Step Approach:**

```cpp
// 1. ANALYZE: What type of two-pointer problem?
//    - Opposite ends: pairs, palindromes, sorted arrays
//    - Same direction: subarrays, duplicates, sliding windows

// 2. INITIALIZE: Set up pointers correctly
int left = 0;                    // For opposite ends
int right = arr.size() - 1;      // For opposite ends
// OR
int slow = 0, fast = 0;          // For same direction

// 3. LOOP: Continue while pointers are valid
while (left < right) {           // Opposite ends
    // Process current elements
    // Decide which pointer(s) to move
}

// 4. UPDATE: Move pointers based on logic
//    - Found target: move both or return
//    - Need larger value: move left right
//    - Need smaller value: move right left
//    - Process element: move appropriate pointer

// 5. RESULT: Return accumulated result or final state
```

---

## 🧪 Practice Problems & Solutions

### 💡 **Quick Practice Set**

```cpp
// Complete main function to test all solutions
int main() {
    cout << "=== TWO-POINTER TECHNIQUE DEMO ===" << endl << endl;
    
    // Test all functions
    testPalindrome();
    cout << endl;
    
    testTwoSum();
    cout << endl;
    
    testWaterContainer();
    cout << endl;
    
    testRemoveDuplicates();
    cout << endl;
    
    testThreeSum();
    cout << endl;
    
    testMoveZeros();
    cout << endl;
    
    return 0;
}
```

### 🏆 **Challenge Problems to Try:**
1. **Valid Palindrome II** - Remove at most one character
2. **Trapping Rain Water** - Calculate trapped rainwater
3. **Sort Colors** - Dutch National Flag problem
4. **Minimum Window Substring** - Advanced sliding window
5. **Longest Substring Without Repeating Characters**

---

## 🎨 Visual Memory Aids

### 🔄 **Opposite Ends Mnemonic:**
```
"Meet in the Middle" 
   ←--------🤝--------→
Think: Handshake, Zipper closing, Books on shelf
```

### 🪟 **Same Direction Mnemonic:**
```
"Chase and Catch"
   →→→→→ (fast runner)
   →→   (slow runner)
Think: Tortoise and hare, Window sliding
```

---

## ⚡ **Pro Tips & Common Pitfalls**

### ✅ **Do's:**
```cpp
// ✅ Always check array bounds
while (left < right && left >= 0 && right < nums.size())

// ✅ Handle duplicates in sorted arrays
while (left < right && nums[left] == nums[left + 1]) left++;

// ✅ Use meaningful variable names
int slow = 0, fast = 0; // Better than i, j

// ✅ Sort array when needed for opposite ends
sort(nums.begin(), nums.end());
```

### ❌ **Don'ts:**
```cpp
// ❌ Wrong loop condition
while (left <= right) // Should be < for most problems

// ❌ Infinite loops
while (left < right) {
    // Forgot to move pointers!
}

// ❌ Accessing out of bounds
if (nums[left] == target) // Check bounds first!
```

---

## 🎯 **Quick Reference Card**

```cpp
// PALINDROME PATTERN
int left = 0, right = s.length() - 1;
while (left < right) {
    if (s[left] != s[right]) return false;
    left++; right--;
}

// TWO SUM PATTERN (sorted array)
int left = 0, right = nums.size() - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) return {left, right};
    else if (sum < target) left++;
    else right--;
}

// REMOVE DUPLICATES PATTERN
int slow = 0;
for (int fast = 1; fast < nums.size(); fast++) {
    if (nums[fast] != nums[slow]) {
        nums[++slow] = nums[fast];
    }
}

// SLIDING WINDOW PATTERN
int left = 0, right = 0;
while (right < nums.size()) {
    // Expand window
    // Shrink window if needed
    // Update result
    right++;
}
```

---

## 🏆 Summary

Two-Pointer technique is your **secret weapon** for:
- ⚡ **Converting O(n²) to O(n)** solutions
- 🎯 **Solving array problems** elegantly  
- 💾 **Using constant extra space**
- 🧠 **Thinking algorithmically** about data traversal

**Remember the golden rules**: 
1. *"If sorted, think opposite ends"*
2. *"If subarrays, think same direction"*
3. *"Always move pointers intelligently"*

---

**Happy Coding! 🚀**