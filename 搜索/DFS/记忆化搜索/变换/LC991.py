from functools import cache

# https://leetcode.cn/problems/broken-calculator/description/


class Solution:
    @cache
    def brokenCalc(self, startValue: int, target: int) -> int:
        if startValue >= target:
            return startValue - target

        if target % 2 == 0:
            return self.brokenCalc(startValue, target // 2) + 1

        return self.brokenCalc(startValue, target + 1) + 1
