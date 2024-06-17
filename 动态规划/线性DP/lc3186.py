from collections import Counter
from typing import List


# https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/description/
# https://leetcode.cn/problems/delete-and-earn/


class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        cnt = Counter(power)
        a = sorted(cnt.keys())
        f = [0] * (len(a) + 1)
        j = 0
        for i, v in enumerate(a):
            while a[j] < v - 2:
                j += 1
            f[i + 1] = max(f[i], f[j] + v * cnt[v])

        return f[-1]
