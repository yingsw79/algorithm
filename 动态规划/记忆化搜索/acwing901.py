import sys
from functools import lru_cache

# https://www.acwing.com/problem/content/903/

# sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(str(x) + "\n")

m, n = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(m)]

dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))


@lru_cache(None)
def dfs(i, j):
    res = 1
    for di, dj in dirs:
        a, b = i + di, j + dj
        if 0 <= a < m and 0 <= b < n and g[a][b] < g[i][j]:
            res = max(res, dfs(a, b) + 1)
    return res


print(max(dfs(i, j) for i in range(m) for j in range(n)))
