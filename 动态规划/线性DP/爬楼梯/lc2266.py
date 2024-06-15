from itertools import groupby

# https://leetcode.cn/problems/count-number-of-texts/description/
# https://leetcode.cn/problems/count-ways-to-build-good-strings/description/
# https://leetcode.cn/problems/combination-sum-iv/description/

MOD = int(1e9 + 7)
N = int(1e5 + 10)
f = [1] + [0] * N
g = [1] + [0] * N
for i in range(1, N):
    for j in range(1, 4):
        if i >= j:
            f[i] += f[i - j]
            g[i] += g[i - j]
    g[i] += g[i - 4]
    f[i] %= MOD
    g[i] %= MOD


class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        res = 1
        for k, v in groupby(pressedKeys):
            n = len(list(v))
            res = (res * (g[n] if k in "79" else f[n])) % MOD
        return res
