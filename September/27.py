# 27. Remove Element

from typing import List


class Solution:
    def removeElement(self, arr: list[int], val: int) -> int:
        k = 0
        for i in arr:
            if i != val:
                arr[k] = i
                k += 1
        return k