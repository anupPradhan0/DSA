# 217. Contains Duplicate

from typing import List


class Solution:
    def containsDuplicate(self, arr: List[int]) -> bool:
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                if arr[i] == arr[j]:
                    return True
        return False



class Solution:
    def containsDuplicate(self, arr: List[int]) -> bool:
        arr2 = sorted(arr)
        for i in range(len(arr2) - 1):
            if arr2[i] == arr2[i+1]:
                return True
        return False




class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))