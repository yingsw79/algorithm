from typing import List

# https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x/description/?envType=daily-question&envId=2024-01-19


class Solution:
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        f = [0] * (len(nums1) + 1)
        for i, (a, b) in enumerate(sorted(zip(nums1, nums2), key=lambda p: p[1])):
            for j in range(i + 1, 0, -1):
                f[j] = max(f[j], f[j - 1] + a + b * j)

        s1 = sum(nums1)
        s2 = sum(nums2)
        for i, v in enumerate(f):
            if s1 + s2 * i - v <= x:
                return i
        return -1
