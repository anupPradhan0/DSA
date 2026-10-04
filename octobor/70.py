# 70. Climbing Stairs

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: return 1
        if n == 2: return 2

        one = 1
        two = 1

        for step in range(2, n + 1):
            current = one + two
            two = one
            one = current

        return one