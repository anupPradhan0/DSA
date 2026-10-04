# 746. Min Cost Climbing Stairs

class Solution:
    def minCostClimbingStairs(self, arr: list[int]) -> int:
        arr.append(0)  # to account for the top of the stairs
        for i in range(2, len(arr)): # To calculate the minimum cost to reach each step, we can use dynamic programming. The cost to reach step i is the cost of step i plus the minimum cost to reach either of the two previous steps (i-1 or i-2). This is because you can reach step i from either step i-1 or step i-2.
            arr[i] += min(arr[i - 1], arr[i - 2]) # To calculate the minimum cost to reach each step, we can use dynamic programming. The cost to reach step i is the cost of step i plus the minimum cost to reach either of the two previous steps (i-1 or i-2). This is because you can reach step i from either step i-1 or step i-2.
        return arr[-1] # TO return the minimum cost to reach the top of the stairs, we can simply return the last element of the modified array, which represents the minimum cost to reach the top.


