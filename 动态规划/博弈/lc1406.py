from functools import cache
from typing import List


# https://leetcode.cn/problems/stone-game-iii/description/
# 比赛一直持续到所有石头都被拿走


class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        for i in range(n - 2, -1, -1):
            stoneValue[i] += stoneValue[i + 1]

        @cache
        def dfs(i):
            if i >= n:
                return 0
            return stoneValue[i] - min(dfs(i + x) for x in range(1, 4))

        s = dfs(0)
        if s * 2 == stoneValue[0]:
            return "Tie"
        return "Alice" if s * 2 > stoneValue[0] else "Bob"


# class Solution:
#     def stoneGameIII(self, stoneValue: List[int]) -> str:
#         n = len(stoneValue)

#         @cache
#         def dfs(i):
#             if i >= n:
#                 return 0
#             return max(sum(stoneValue[i : i + x]) - dfs(i + x) for x in range(1, 4))

#         d = dfs(0)
#         if d > 0:
#             return "Alice"
#         elif d < 0:
#             return "Bob"
#         else:
#             return "Tie"
