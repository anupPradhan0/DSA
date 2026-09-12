# 53. Maximum Subarray

from typing import List

class Solution: # [-2,1,-3,4,-1,2,1,-5,4]
    def maxSubArray(self, arr: List[int]) -> int:
        maxSum = arr[0] # -2
        for i in range(len(arr)):
            currentSum = 0
            for j in range(i, len(arr)):
                currentSum += arr[j]
                maxSum = max(maxSum, currentSum)
        return maxSum




# Kadane's Algorithm.
# Time O(n)
# space O(1)

class Solution: # [-2,1,-3,4,-1,2,1,-5,4]
    def maxSubArray(self, arr: List[int]) -> int:
        gmax = arr[0]
        cmax = arr[0]
        for i in range(1, len(arr)):
            cmax = max(arr[i], arr[i] + cmax)
            gmax = max(cmax, gmax)
        return gmax


class Solution:
    def maxSubArray(self, arr: List[int]) -> int:
        gmax = arr[0]
        cmax = arr[0]

        for i in range(1, len(arr)):
            if arr[i] > arr[i] + cmax:
                cmax = arr[i]
            else:
                cmax = arr[i] + cmax

            if cmax > gmax:
                gmax = cmax

        return gmax