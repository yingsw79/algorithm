from functools import cache
from typing import List


# https://leetcode.cn/problems/burst-balloons/description/?envType=daily-question&envId=2024-06-09


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]

        @cache
        def dfs(l, r):
            res = 0
            for i in range(l + 1, r):
                res = max(res, dfs(l, i) + dfs(i, r) + nums[l] * nums[i] * nums[r])
            return res

        return dfs(0, len(nums) - 1)
