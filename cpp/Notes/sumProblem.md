# 🎯 ThreeSum Algorithm - Finding Magic Number Triplets! 

> *Understanding the ThreeSum problem like you're 5 years old* 🧒

## 🎲 The Problem (ThreeSum)

Imagine you have a **box full of numbers** (some positive ➕, some negative ➖).

Your mission: **Find all groups of 3 numbers that add up to zero!** 

```
Example: [-1, 0, 1, 2, -1, -4]
Goal: Find triplets that sum to 0
Answer: [[-1, -1, 2], [-1, 0, 1]]
```

---

## 🧩 The Solution Step-by-Step

### 👣 Step 1: Sorting the Numbers
**Like organizing toys from smallest to biggest!**

```cpp
sort(arr.begin(), arr.end());
```

**Before**: `[-1, 0, 1, 2, -1, -4]` (messy!)  
**After**: `[-4, -1, -1, 0, 1, 2]` (organized!)

**Why sort?** 🤔  
- Makes it easier to avoid duplicates  
- Enables the two-pointer technique  
- We can control the sum by moving left/right

---

### 👣 Step 2: Fix the First Number
**Pick one number to "stand still" while others dance around it!**

```cpp
for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i] == arr[i-1]) continue; // Skip duplicates
    // ... rest of the magic
}
```

```
Fixed number: arr[i] = -1
Remaining array: [-1, 0, 1, 2]
           ↑           ↑
          st          end
```

---

### 👣 Step 3: Two Little Friends (Two Pointers)
**Set up two pointers like bookends!**

```cpp
int st = i + 1;    // Start pointer (left bookend)
int end = n - 1;   // End pointer (right bookend)
```

```
Array: [-4, -1, -1, 0, 1, 2]
        ↑       ↑           ↑
        i      st         end
```

---

### 👣 Step 4: The Magic Dance
**Add the three numbers and see what happens!**

```cpp
while (st < end) {
    int sum = arr[i] + arr[st] + arr[end];
    
    if (sum < 0)      st++;     // Too small → need bigger number
    else if (sum > 0) end--;    // Too big → need smaller number
    else {                      // Perfect! → found a triplet
        ans.push_back({arr[i], arr[st], arr[end]});
        st++; end--;
        // Skip duplicates
        while (st < end && arr[st] == arr[st-1]) st++;
        while (st < end && arr[end] == arr[end+1]) end--;
    }
}
```

### 🎯 Three Possible Outcomes:

| Sum Result | Action | Reason |
|------------|--------|---------|
| `sum < 0` | `st++` | Need bigger number → move left pointer right |
| `sum > 0` | `end--` | Need smaller number → move right pointer left |
| `sum == 0` | 🎉 **Found it!** | Add to answer and continue searching |

---

## 💫 Complete Code Solution

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Fix first number
        for (int i = 0; i < n; i++) {
            // Skip duplicates for first number
            if (i > 0 && arr[i] == arr[i-1]) continue;
            
            // Step 3: Set up two pointers
            int st = i + 1;
            int end = n - 1;
            
            // Step 4: Find valid triplets
            while (st < end) {
                int sum = arr[i] + arr[st] + arr[end];
                
                if (sum < 0) {
                    st++;  // Need bigger number
                } else if (sum > 0) {
                    end--; // Need smaller number
                } else {
                    // Found a triplet!
                    ans.push_back({arr[i], arr[st], arr[end]});
                    st++;
                    end--;
                    
                    // Step 5: Skip duplicates
                    while (st < end && arr[st] == arr[st-1]) st++;
                    while (st < end && arr[end] == arr[end+1]) end--;
                }
            }
        }
        return ans;
    }
};
```

---

## 📊 Example Walkthrough

Let's trace through: `[-1, 0, 1, 2, -1, -4]`

### 🔄 Step-by-Step Execution:

```
Original: [-1, 0, 1, 2, -1, -4]
Sorted:   [-4, -1, -1, 0, 1, 2]
```

#### Round 1: Fix `i = 0` (arr[i] = -4)
```
Array: [-4, -1, -1, 0, 1, 2]
        ↑    ↑           ↑
        i   st         end

Target: Need two numbers that sum to +4
Try: -4 + (-1) + 2 = -3 ❌ (too small → st++)
Try: -4 + (-1) + 1 = -4 ❌ (too small → st++)  
Try: -4 + 0 + 2 = -2 ❌ (too small → st++)
Try: -4 + 1 + 2 = -1 ❌ (too small → no more moves)
Result: No triplets found 😞
```

#### Round 2: Fix `i = 1` (arr[i] = -1)
```
Array: [-4, -1, -1, 0, 1, 2]
            ↑    ↑        ↑
            i   st      end

Target: Need two numbers that sum to +1
Try: -1 + (-1) + 2 = 0 🎉 Found: [-1, -1, 2]
Try: -1 + 0 + 1 = 0 🎉 Found: [-1, 0, 1]
```

#### Round 3: Fix `i = 2` (arr[i] = -1)
```
Skipped! (duplicate of previous -1)
```

#### Final Answer: `[[-1, -1, 2], [-1, 0, 1]]` 🎯

---

## 🎨 Visual Memory Aid

```
    ThreeSum Strategy:
    
    🎯 Fixed Number + Two Dancers
    ┌─────────────────────────────┐
    │  arr[i]    arr[st]  arr[end] │
    │    ↓         ↓        ↓      │
    │   📍       👈        👉     │
    │  (fixed)   (left)   (right)  │
    └─────────────────────────────┘
    
    📏 Movement Rules:
    Sum < 0 → 👈 moves right (bigger number)
    Sum > 0 → 👉 moves left (smaller number)  
    Sum = 0 → 🎉 Found triplet!
```

---

## ⚡ Performance Analysis

```cpp
🚀 Time Complexity: O(n²)
├── Sorting: O(n log n)
├── Outer loop: O(n)
└── Inner two pointers: O(n)

💾 Space Complexity: O(1)
└── Only using constant extra space (not counting output)
```

**Translation**: For 1000 numbers, roughly 1 million operations - very efficient! 🎯

---

## 🎯 Key Insights & Tricks

### ✨ Why This Algorithm Works:
1. **Sorting** enables duplicate skipping and two-pointer technique
2. **Fixed first element** reduces 3-sum to 2-sum problem
3. **Two pointers** efficiently explore all possibilities
4. **Duplicate handling** ensures unique triplets

### 🔍 Edge Cases to Remember:
```cpp
// Empty or too small array
if (n < 3) return {};

// All zeros
[0, 0, 0] → [[0, 0, 0]]

// No solution exists
[1, 2, 3] → []

// Duplicates everywhere  
[-1, -1, -1, 2, 2, 2] → [[-1, -1, 2]]
```

---

## 🧪 Test Your Understanding

```cpp
Input: [0, 1, 1]
Question: What will be the output?

A) [[0, 1, 1]]
B) []  
C) [[1, 1, 0]]
```

<details>
<summary>🔍 Click for answer</summary>

**Answer**: B) `[]`

**Explanation**: 
- After sorting: `[0, 1, 1]`
- Fix i=0 (value=0): need two numbers that sum to 0
- st=1 (value=1), end=2 (value=1)
- Sum: 0 + 1 + 1 = 2 ≠ 0
- Move end left → st >= end → no solution

No three numbers sum to zero! 😅

</details>

---

## 🚀 Pro Tips

1. **Always sort first** - enables the two-pointer technique
2. **Handle duplicates carefully** - both in outer loop and inner pointers
3. **Use early termination** - if arr[i] > 0, no more negatives to balance
4. **Watch pointer boundaries** - ensure st < end always
5. **Consider edge cases** - arrays with < 3 elements

---

## 🔗 Related Problems

| Problem | Difficulty | Key Difference |
|---------|------------|----------------|
| Two Sum | Easy | Find pair that sums to target |
| Four Sum | Medium | Find quadruplets that sum to target |
| 3Sum Closest | Medium | Find triplet closest to target |
| 3Sum Smaller | Medium | Count triplets with sum < target |

---

## 🎉 Conclusion

The **ThreeSum algorithm** is a beautiful example of:
- **Smart preprocessing** (sorting) 🧠
- **Divide and conquer** (fix one, solve for two) ⚔️  
- **Efficient searching** (two pointers) 🎯
- **Careful duplicate handling** (uniqueness) 🎨

Master this pattern, and you'll crush similar problems! 💪

---

*Happy coding! 🚀*

> ⭐ **Star this repo** if it helped you understand ThreeSum!
> 
> 🐛 **Found an issue?** Open an issue or submit a PR!
> 
> 💬 **Questions?** Feel free to reach out!