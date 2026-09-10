# 121. Best Time to Buy and Sell Stock

from rpds import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices == 0:
            return 0
        minV = prices[0]
        maxV = 0
        for price in prices:
            minV = min(minV, price)
            maxV = max(maxV, price - minV)
        return maxV
    