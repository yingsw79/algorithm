from collections import Counter
from typing import List

# https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/description/


class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        if 6 * len(nums1) < len(nums2) or 6 * len(nums2) < len(nums1):
            return -1  # 优化
        d = sum(nums2) - sum(nums1)
        if d < 0:
            d = -d
            nums1, nums2 = nums2, nums1  # 统一让 nums1 的数变大，nums2 的数变小
        ans = 0
        cnt = Counter(6 - x for x in nums1) + Counter(x - 1 for x in nums2)
        for i in range(5, 0, -1):
            if i * cnt[i] >= d:
                return ans + (d + i - 1) // i
            ans += cnt[i]
            d -= i * cnt[i]


# class Solution:
#     def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
#         s1 = sum(nums1)
#         s2 = sum(nums2)
#         if s1 == s2:
#             return 0
#         res = 0
#         d = abs(s1 - s2)
#         if s1 < s2:
#             nums1, nums2 = nums2, nums1
#         changes = [x - 1 for x in nums1 if x > 1]
#         changes.extend(6 - x for x in nums2 if x < 6)
#         changes.sort(reverse=True)
#         for x in changes:
#             d -= min(x, d)
#             res += 1
#             if d == 0:
#                 break
#         if d == 0:
#             return res
#         return -1
