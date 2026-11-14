# 125. Valid Palindrome


class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        lett = "".join(char.lower() for char in s if char.isalnum())

        
        # if lett == lett[::-1]:
        #     return True
        # else:
        #     return False
        
        return lett == lett[::-1]