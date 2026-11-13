# 9. Palindrome Number

class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False
        x = str(x)
        l = 0 
        r = len(x) -1

        while l < r :
            while l < r and not x[l].isalnum():
                l += 1
            while l < r and not x[r].isalnum():
                r -= 1
            if x[l].lower() != x[r].lower():
                return False
            l += 1
            r -= 1

        return True