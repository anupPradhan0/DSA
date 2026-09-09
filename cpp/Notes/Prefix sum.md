# 📘 Prefix Sum - The Ultimate Cumulative Magic! 

> *Master the art of preprocessing for lightning-fast subarray queries* ⚡

## 🎯 What is Prefix Sum?

**Prefix Sum** is a preprocessing technique where we **precompute cumulative sums** to avoid recalculating them repeatedly.

Think of it like a **running total** that keeps track of everything we've seen so far!

### 📊 Formal Definition:
For array `arr = [a₀, a₁, a₂, ..., aₙ₋₁]`, the prefix sum array `pre` is:

```
pre[i] = a₀ + a₁ + a₂ + ... + aᵢ
```

### 🌟 Simple Example:
```cpp
Original: arr = [2, 3, 5, -2]
Prefix:   pre = [2, 5, 10, 8]

Explanation:
pre[0] = 2                    // Just first element
pre[1] = 2 + 3 = 5           // Sum of first 2 elements  
pre[2] = 2 + 3 + 5 = 10      // Sum of first 3 elements
pre[3] = 2 + 3 + 5 + (-2) = 8 // Sum of all elements
```

---

## 🔧 How to Compute Prefix Sum

### Method 1: Basic Implementation
```cpp
vector<int> computePrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> pre(n);
    
    pre[0] = arr[0];  // Base case
    
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i-1] + arr[i];  // Running total
    }
    
    return pre;
}
```

### Method 2: In-Place (Space Optimized)
```cpp
void computePrefixSumInPlace(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        arr[i] += arr[i-1];  // Modify original array
    }
    // Now arr contains prefix sums!
}
```

### ⚡ Complexity:
- **Time**: O(n) - Single pass through array
- **Space**: O(n) for separate array, O(1) for in-place

---

## 🎯 The Magic Formula: Subarray Sum Query

The **real power** of prefix sums: Find sum of any subarray `arr[l..r]` in **O(1)** time!

### 🔮 The Formula:
```cpp
sum(l, r) = pre[r] - pre[l-1]

Special case: If l = 0, then sum(0, r) = pre[r]
```

### 📈 Visual Example:
```cpp
arr = [2, 3, 5, -2]
pre = [2, 5, 10, 8]

Query: Sum of arr[1..3] = 3 + 5 + (-2) = 6

Using formula:
sum(1, 3) = pre[3] - pre[0] = 8 - 2 = 6 ✅

Visual representation:
[2] [3, 5, -2]
 ↑      ↑
pre[0] Elements we want (sum = 6)

Total sum - Unwanted prefix = 8 - 2 = 6
```

### 🎮 Interactive Demo:
```cpp
#include <vector>
#include <iostream>
using namespace std;

class PrefixSum {
    vector<int> pre;
public:
    PrefixSum(vector<int>& arr) {
        int n = arr.size();
        pre.resize(n);
        pre[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + arr[i];
        }
    }
    
    int rangeSum(int l, int r) {
        if (l == 0) return pre[r];
        return pre[r] - pre[l-1];
    }
};

int main() {
    vector<int> arr = {2, 3, 5, -2, 1};
    PrefixSum ps(arr);
    
    cout << ps.rangeSum(1, 3) << endl;  // Output: 6
    cout << ps.rangeSum(0, 4) << endl;  // Output: 9
    return 0;
}
```

---

## 🎨 Visual Memory Aid

```
    Original Array: [2, 3, 5, -2, 1]
                     ↓  ↓  ↓   ↓  ↓
    Prefix Sum:     [2, 5, 10, 8, 9]
    
    🎯 Query arr[1..3]:
    
    ┌─────┬─────┬─────┬─────┬─────┐
    │  2  │  3  │  5  │ -2  │  1  │
    └─────┴─────┴─────┴─────┴─────┘
      ↑           ↑─────────↑
   pre[0]=2    We want this part
   
   Formula: pre[3] - pre[0] = 8 - 2 = 6 ✅
```

---

## 🚀 Advanced: HashMap + Prefix Sum

**The ultimate combo** for subarray problems! 🔥

### 🎯 Problem: Count subarrays with sum = K

**Key Insight**: For subarray `arr[j..i]` to have sum K:
```
pre[i] - pre[j-1] = K
→ pre[j-1] = pre[i] - K
```

So if we've seen `pre[i] - K` before, there's a subarray ending at `i` with sum K!

### 💎 Implementation:
```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;  // Base case: empty prefix
    
    int prefixSum = 0;
    int count = 0;
    
    for (int num : nums) {
        prefixSum += num;  // Update running sum
        
        // Check if (prefixSum - k) exists
        if (prefixCount.count(prefixSum - k)) {
            count += prefixCount[prefixSum - k];
        }
        
        // Add current prefix sum to map
        prefixCount[prefixSum]++;
    }
    
    return count;
}
```

### 📊 Step-by-Step Trace:
```cpp
Input: nums = [1, 1, 1], k = 2

Step 0: prefixCount = {0: 1}, prefixSum = 0, count = 0

Step 1: num = 1
- prefixSum = 0 + 1 = 1
- Check prefixCount[1 - 2] = prefixCount[-1] → not found
- prefixCount[1]++
- prefixCount = {0: 1, 1: 1}, count = 0

Step 2: num = 1  
- prefixSum = 1 + 1 = 2
- Check prefixCount[2 - 2] = prefixCount[0] → found! count += 1
- prefixCount[2]++
- prefixCount = {0: 1, 1: 1, 2: 1}, count = 1

Step 3: num = 1
- prefixSum = 2 + 1 = 3  
- Check prefixCount[3 - 2] = prefixCount[1] → found! count += 1
- prefixCount[3]++
- Final count = 2

Answer: 2 subarrays with sum 2: [1,1] and [1,1]
```

---

## 🌟 Common Applications

### 1. **Range Sum Queries** ⚡
```cpp
// After O(n) preprocessing, answer queries in O(1)
int rangeSum(int l, int r) {
    return pre[r] - (l > 0 ? pre[l-1] : 0);
}
```

### 2. **Subarray Sum Problems** 🎯
- Count subarrays with sum = K
- Find max/min subarray sum  
- Subarray sum divisible by K
- Binary subarray with sum

### 3. **2D Prefix Sums** 🗺️
```cpp
// For matrix range sum queries
int mat[n][m], pre[n][m];

// Preprocessing
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        pre[i][j] = mat[i][j];
        if (i > 0) pre[i][j] += pre[i-1][j];
        if (j > 0) pre[i][j] += pre[i][j-1];
        if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
    }
}

// Query sum of rectangle (r1,c1) to (r2,c2)
int rectangleSum(int r1, int c1, int r2, int c2) {
    int result = pre[r2][c2];
    if (r1 > 0) result -= pre[r1-1][c2];
    if (c1 > 0) result -= pre[r2][c1-1];  
    if (r1 > 0 && c1 > 0) result += pre[r1-1][c1-1];
    return result;
}
```

### 4. **Difference Arrays** (Range Updates) ⚡
```cpp
// For multiple range updates followed by queries
vector<int> diff(n+1, 0);

// Update range [l,r] by adding val
void rangeUpdate(int l, int r, int val) {
    diff[l] += val;
    diff[r+1] -= val;
}

// Build final array after all updates
vector<int> buildArray() {
    vector<int> result(n);
    result[0] = diff[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i-1] + diff[i];
    }
    return result;
}
```

---

## 🎯 Performance Analysis

| Operation | Without Prefix Sum | With Prefix Sum |
|-----------|-------------------|-----------------|
| **Preprocessing** | - | O(n) |
| **Single Query** | O(n) | O(1) |
| **Q Queries** | O(Q×n) | O(Q) |
| **Space** | O(1) | O(n) |

### 🚀 When to Use Prefix Sum:
✅ **Perfect for:**
- Multiple range sum queries
- Subarray sum problems  
- Cumulative operations
- Problems with "running totals"

❌ **Not suitable for:**
- Single query on changing data
- When array is frequently modified
- Memory-constrained environments

---

## 🧪 Practice Problems

### 🟢 Easy:
1. **Range Sum Query - Immutable** (LeetCode 303)
2. **Running Sum of 1D Array** (LeetCode 1480)

### 🟡 Medium:
1. **Subarray Sum Equals K** (LeetCode 560)
2. **Range Sum Query 2D - Immutable** (LeetCode 304)  
3. **Continuous Subarray Sum** (LeetCode 523)

### 🔴 Hard:
1. **Maximum Sum Rectangle** (GeeksforGeeks)
2. **Count of Range Sum** (LeetCode 327)

---

## 🎉 Key Takeaways

### ✨ **Core Concepts:**
1. **Prefix sum = cumulative totals** stored once to avoid recalculation
2. **Subarray sum formula**: `sum(l,r) = pre[r] - pre[l-1]`  
3. **HashMap combo**: Solves "count subarrays with sum K" in O(n)
4. **Think prefix sums** for repeated sum queries or subarray constraints

### 🧠 **Memory Tricks:**
- **"Running total"** - keep adding as you go
- **"Remove unwanted prefix"** - subtract what you don't need
- **"HashMap tracks seen prefixes"** - for subarray counting

### 🚀 **Pro Tips:**
- Handle **l=0** case separately in range queries
- Use **0-indexed** prefix sum for simplicity
- **HashMap[0] = 1** for empty prefix in subarray problems
- Consider **in-place** computation to save space

---

## 🎮 Quick Quiz

```cpp
Given arr = [1, -1, 0, 2, -1], pre = [1, 0, 0, 2, 1]

Q1: What is sum of arr[1..3]?
Q2: How many subarrays have sum = 0?
```

<details>
<summary>🔍 Click for answers</summary>

**Q1**: `sum(1,3) = pre[3] - pre[0] = 2 - 1 = 1` ✅

**Q2**: Using HashMap technique:
- Prefix sums: [1, 0, 0, 2, 1]  
- Count of 0: appears at index 1 and 2
- Subarrays with sum 0: arr[1..1], arr[2..2], arr[1..2] 
- **Answer: 3** ✅

</details>

---

*Happy coding with prefix sums! 🚀*

> ⭐ **Star this repo** if you mastered prefix sums!
> 
> 🐛 **Found an issue?** Open an issue or submit a PR!
> 
> 💬 **Questions?** Feel free to reach out!