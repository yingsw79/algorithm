import sys

input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(str(x) + "\n")


# https://atcoder.jp/contests/abc363/tasks/abc363_f


def dfs(s: str) -> str:
    if "0" not in s and s == s[::-1]:
        return s
    x = 2
    n = int(s)
    while x <= n // x:
        xs = str(x)
        if n % x != 0 or "0" in xs:
            x += 1
            continue
        ys = xs[::-1]
        y = int(ys)
        if n // x % y != 0:
            x += 1
            continue
        t = dfs(str(n // x // y))
        if t:
            return xs + "*" + t + "*" + ys
        x += 1
    return ""


res = dfs(input())
if res:
    print(res)
else:
    print(-1)
