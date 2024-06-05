from functools import cache
from math import inf
from typing import List

# https://leetcode.cn/problems/cherry-pickup/description/


class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dirs = (0, -1)

        @cache
        def dfs(i, j, k):
            if i < 0 or j < 0 or k - i < 0 or k - j < 0 or grid[i][k - i] < 0 or grid[j][k - j] < 0:
                return -inf
            if k == 0:
                return grid[0][0]
            return max(dfs(i + a, j + b, k - 1) for a in dirs for b in dirs) + grid[i][k - i] + (grid[j][k - j] if i != j else 0)

        return max(dfs(n - 1, n - 1, n * 2 - 2), 0)
