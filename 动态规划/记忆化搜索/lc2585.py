from functools import cache
from typing import List

# https://leetcode.cn/problems/number-of-ways-to-earn-points/
# 暴搜+记忆化


class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
        MOD = int(1e9 + 7)
        n = len(types)

        @cache
        def dfs(i, sum):
            if sum == 0:
                return 1
            if i == n:
                return 0

            res = 0
            for j in range(types[i][0] + 1):
                t = sum - j * types[i][1]
                if t >= 0:
                    res = (res + dfs(i + 1, t)) % MOD
                else:
                    break

            return res

        return dfs(0, target)
