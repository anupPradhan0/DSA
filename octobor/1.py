
# 1.Two Sum


class Solution(object):
    def twoSum(self,arr, target):
        index = {}
        for i in range(len(arr)):
            complement = target - arr[i]
            if complement in index:
                return [index[complement], i]
            index[arr[i]] = i

        return None
