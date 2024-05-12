from functools import cache


# https://leetcode.cn/problems/minimum-number-of-days-to-eat-n-oranges/?envType=daily-question&envId=2024-05-12


class Solution:
    def minDays(self, n: int) -> int:
        @cache
        def dfs(x):
            if x <= 1:
                return x

            return min(dfs(x // 2) + x % 2, dfs(x // 3) + x % 3) + 1

        return dfs(n)
