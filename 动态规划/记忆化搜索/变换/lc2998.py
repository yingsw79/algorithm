from functools import cache

# https://leetcode.cn/problems/minimum-number-of-operations-to-make-x-and-y-equal/description/


class Solution:
    @cache
    def minimumOperationsToMakeEqual(self, x: int, y: int) -> int:
        if x <= y:
            return y - x

        return min(
            x - y,
            self.minimumOperationsToMakeEqual(x // 11, y) + x % 11 + 1,
            self.minimumOperationsToMakeEqual(x // 11 + 1, y) + 11 - x % 11 + 1,
            self.minimumOperationsToMakeEqual(x // 5, y) + x % 5 + 1,
            self.minimumOperationsToMakeEqual(x // 5 + 1, y) + 5 - x % 5 + 1,
        )
