from functools import reduce
from math import gcd


class Solution:
    def minOperations(self, nums: list[int], numsDivide: list[int]) -> int:
        g = reduce(gcd, numsDivide)
        nums.sort()
        return next((i for i, x in enumerate(nums) if g % x == 0), -1)

