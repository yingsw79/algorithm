from functools import cache


# https://leetcode.cn/problems/can-i-win/description/
# 直到累计整数和 >= desiredTotal


class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False

        @cache
        def dfs(mask):
            s = sum(i + 1 for i in range(maxChoosableInteger) if (mask >> i) & 1)
            for i in range(maxChoosableInteger):
                if (mask >> i) & 1:
                    continue
                if s + i + 1 >= desiredTotal or not dfs(mask | (1 << i)):
                    return True
            return False

        return dfs(0)
