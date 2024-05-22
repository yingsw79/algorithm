from typing import List
from functools import cache
from math import inf

# https://leetcode.cn/problems/minimum-sum-of-values-by-dividing-array/description/

class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        n, m = len(nums), len(andValues)

        @cache
        def dfs(i, j, v):
            if m - j > n - i:
                return inf

            if j == m:
                return 0 if i == n else inf

            v &= nums[i]
            if v < andValues[j]:
                return inf

            res = dfs(i + 1, j, v)
            if v == andValues[j]:
                res = min(res, dfs(i + 1, j + 1, -1) + nums[i])
            return res

        res = dfs(0, 0, -1)
        return res if res < inf else -1
