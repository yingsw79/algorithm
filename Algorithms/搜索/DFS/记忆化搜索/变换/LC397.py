from functools import cache


# https://leetcode.cn/problems/integer-replacement/description/


class Solution:
    @cache
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 0

        if n % 2 == 0:
            return self.integerReplacement(n // 2) + 1

        return min(self.integerReplacement(n + 1), self.integerReplacement(n - 1)) + 1
