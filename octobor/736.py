# 746. Min Cost Climbing Stairs

class Solution:
    def minCostClimbingStairs(self, arr: list[int]) -> int:
        arr.append(0)
        for i in range(2, len(arr)):
            arr[i] += min(arr[i - 1], arr[i - 2])
        return arr[-1]