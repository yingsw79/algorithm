from functools import cache

# https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/?envType=daily-question&envId=2024-08-05


class Solution:
    def findIntegers(self, n: int) -> int:
        s = bin(n)[2:]

        @cache
        def dfs(i, pre, isLimit, isNum):
            if i == len(s):
                return isNum
            res = 0
            if not isNum:
                res = dfs(i + 1, pre, False, False)
            lo = 1 - isNum
            hi = int(s[i]) if isLimit else 1
            for x in range(lo, hi + 1):
                if pre and x:
                    continue
                res += dfs(i + 1, x, isLimit and x == hi, True)
            return res

        return dfs(0, 0, True, False) + 1
