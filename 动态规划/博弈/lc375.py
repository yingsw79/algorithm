from functools import cache

# https://leetcode.cn/problems/guess-number-higher-or-lower-ii/description/


class Solution:
    def getMoneyAmount(self, n: int) -> int:
        @cache
        def dfs(i, j):
            if i >= j:
                return 0
            return min(k + max(dfs(k + 1, j), dfs(i, k - 1)) for k in range(i, j + 1))

        return dfs(1, n)
