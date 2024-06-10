from functools import cache
from typing import List

# https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-ii/description/?envType=daily-question&envId=2024-06-08


class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        n = len(nums)

        @cache
        def dfs(i, j, s):
            if i >= j:
                return 0

            res = 0
            if nums[i] + nums[i + 1] == s:
                res = max(res, dfs(i + 2, j, s) + 1)
            if nums[i] + nums[j] == s:
                res = max(res, dfs(i + 1, j - 1, s) + 1)
            if nums[j] + nums[j - 1] == s:
                res = max(res, dfs(i, j - 2, s) + 1)
            return res

        return max(dfs(2, n - 1, nums[0] + nums[1]), dfs(1, n - 2, nums[0] + nums[-1]), dfs(0, n - 3, nums[-1] + nums[-2])) + 1
