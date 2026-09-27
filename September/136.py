# 136. Single Number

class Solution:
    def singleNumber(self, arr: list[int]) -> int:
        unique = 0

        for num in arr:
            unique ^= num

        return unique



class Solution:
    def singleNumber(self, arr: list[int]) -> int:
        arr.sort()
        left = 0

        while left < len(arr) - 1:
            if arr[left] != arr[left + 1]:
                return arr[left]
            left += 2

        return arr[-1]