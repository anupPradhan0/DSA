# 283. Move Zeroes

from typing import List


class Solution:
    def moveZeroes(self, arr: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(arr)-1, -1, -1):
            if arr[i] == 0:
                arr.pop(i)
                arr.append(0)
        return arr



class Solution:
    def moveZeroes(self, arr: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pointer = 0 # Left 

        for i in range(len(arr)): # Right = i
            if arr[i] != 0:
                arr[pointer] = arr[i]
                pointer += 1 

        while pointer < len(arr):
            arr[pointer] = 0
            pointer +=1

        return arr


class Solution:
    def moveZeroes(self, arr: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        point = 0
        for r in range(len(arr)):
            if arr[r]:
                arr[point], arr[r] = arr[r], arr[point]
                point += 1
        return arr
