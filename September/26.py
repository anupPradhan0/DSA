# 26. Remove Duplicates from Sorted Array


# Wrong Answer
# 188 / 362 testcases passed

from typing import List

class Solution:
    def removeDuplicates(self, arr: List[int]) -> int:
        R = set(arr)
        arr[:] = list(R)
        arr.sort()
        return len(R)



# Two opinter approach

class Solution:
    def removeDuplicates(self, arr: List[int]) -> int:
        if len(arr) ==  0:
            return 0
        k = 0
        for i in arr:
            if arr[k] != i:
                k += 1
                arr[k] = i
        return k + 1