from functools import cache


class Solution:
    def waysToReachStair(self, k: int) -> int:
        @cache
        def dfs(i, j, down):
            if i > k + 1:
                return 0

            res = 1 if i == k else 0
            res += dfs(i + (1 << j), j + 1, False)
            if i > 0 and not down:
                res += dfs(i - 1, j, True)

            return res

        return dfs(1, 0, False)
