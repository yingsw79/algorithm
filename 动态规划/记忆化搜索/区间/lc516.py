from functools import cache

# https://leetcode.cn/problems/longest-palindromic-subsequence/description/


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @cache
        def dfs(i, j):
            if i > j:
                return 0
            elif i == j:
                return 1
            res = 0
            if s[i] == s[j]:
                res = max(res, dfs(i + 1, j - 1) + 2)
            else:
                res = max(res, dfs(i + 1, j), dfs(i, j - 1))
            return res

        return dfs(0, len(s) - 1)
