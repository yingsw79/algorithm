from collections import defaultdict
from math import inf
from typing import List


# https://leetcode.cn/problems/find-the-sum-of-subsequence-powers/description/?envType=daily-question&envId=2024-07-23


class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        MOD = int(1e9 + 7)
        n = len(nums)
        res = 0
        f = [[defaultdict(int) for _ in range(k + 1)] for _ in range(n)]
        nums.sort()

        for i in range(n):
            f[i][1][inf] = 1
            for j in range(i):
                d = abs(nums[i] - nums[j])
                for p in range(2, k + 1):
                    for v, cnt in f[j][p - 1].items():
                        f[i][p][min(d, v)] = (f[i][p][min(d, v)] + cnt) % MOD

            for v, cnt in f[i][k].items():
                res = (res + v * cnt % MOD) % MOD

        return res
