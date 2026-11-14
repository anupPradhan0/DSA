# 189. Rotate Array

class Solution(object):
    def rotate(self, arr, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        # n = len(arr)
        # if n > 0: k = k % n


        # for _ in range(k):
        #     last = arr[n-1]

        #     for j in range(n-1, 0, -1):
        #         arr[j] = arr[j-1]

        #     arr[0] = last

        n = len(arr) 
        if n > 0: k = k % n
        lis = []

        for i in range(n-k, n):
            lis.append(arr[i])
        for i in range(n-k):
            lis.append(arr[i])
        for i in range(n):
            arr[i] = lis[i]

    

               
        