# 344. Reverse String

class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        # n = len(s)

        # for i in range(n):
        #     for j in range(n - 1, -1, -1):
        #         if i + j == n - 1 and i < j:
        #             s[i], s[j] = s[j], s[i]

        # l = 0
        # r = len(s) -1

        # while l < r:
        #     s[l], s[r] = s[r], s[l]
        #     l +=1
        #     r +=1

        # return s.reverse()

        n = len(s)
        s2  = []
        for i in range(n -1, -1, -1):
            s2.append(s[i])
        s[:] = s2




class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """

        # return s.reverse()

        n = len(n)

        # for i in range(n):
        #     for j in range(n-1, -1, -1):
        #         if i + j == n-1 and i < j:
        #             s[i], s[j] = s[j], s[i]

        # l = 0
        # r = n-1
        # while l < r:
        #     s[l], s[r] = s[r], s[l]
        #     l +=1
        #     r -=1

        # ans = []
        # for i in range(n-1, -1, -1):
        #     ans.append(s[i])
        # s[:] = ans