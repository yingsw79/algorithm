from functools import cache
from math import inf
from typing import List


class Solution:
    def findPermutation(self, a: List[int]) -> List[int]:
        n = len(a)

        @cache
        def dfs(s: int, j: int) -> int:
            if s == (1 << n) - 1:
                # 所有位置都填完了，最后一个位置是下标 j
                return abs(j - a[0])
            res = inf
            # 枚举当前位置填下标 k
            for k in range(1, n):
                if s >> k & 1 == 0:  # k 之前没填过
                    res = min(res, dfs(s | 1 << k, k) + abs(j - a[k]))
            return res

        ans = []

        def make_ans(s: int, j: int) -> None:
            ans.append(j)
            if s == (1 << n) - 1:
                return
            final_res = dfs(s, j)
            for k in range(1, n):
                if s >> k & 1 == 0 and dfs(s | 1 << k, k) + abs(j - a[k]) == final_res:
                    make_ans(s | 1 << k, k)
                    break

        make_ans(1, 0)
        return ans
