from functools import cache
from typing import List

# https://leetcode.cn/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-05-07


class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1)

        @cache
        def dfs(i, j, k):
            if i >= m or j < 0 or j >= n or k < 0 or k >= n:
                return 0

            return max(dfs(i + 1, j + a, k + b) for a in dirs for b in dirs) + grid[i][j] + (grid[i][k] if j != k else 0)

        return dfs(0, 0, n - 1)
