# 169. Majority Element

class Solution:
    def majorityElement(self, arr: list[int]) -> int:
        arr.sort()
        ans = 0
        count = 0
        for i in range(len(arr)):
            if i > 0 and arr[i] == arr[i - 1]:
                count += 1
            else:
                count = 1
            if count > len(arr) // 2:
                ans = arr[i]
                break
        return ans