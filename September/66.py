# 66. Plus One

class Solution:
    def plusOne(self, arr: list[int]) -> list[int]:
        for i in range(len(arr) -1, -1, -1):
            if arr[i] < 9:
                arr[i] += 1
                return arr

            arr[i] = 0


        return [1]+ arr