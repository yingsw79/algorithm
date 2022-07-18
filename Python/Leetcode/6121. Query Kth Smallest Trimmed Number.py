# https://leetcode.cn/problems/query-kth-smallest-trimmed-number/

# 保留原始下标用值排序（稳定，值相等下标小的在前面）的方法是组合成一个元组
class Solution:
    def smallestTrimmedNumbers(self, nums: list[str], queries: list[list[int]]) -> list[int]:
        return [sorted((s[-trim:], i) for i, s in enumerate(nums))[k - 1][1] for k, trim in queries]


nums = ["102", "473", "251", "814"]
queries = [[1, 1], [2, 3], [4, 2], [1, 2]]
s = Solution()
res = s.smallestTrimmedNumbers(nums, queries)
print(res)
