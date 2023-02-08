from collections import Counter, defaultdict
from itertools import pairwise
from math import sqrt
import math
from typing import List


class Solution:

    def frequencySort(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        nums.sort(key=lambda x: (cnt[x], -x))
        return nums


class Solution:

    def countTime(self, time: str) -> int:

        def check(s: str) -> bool:
            hh, mm = s.split(":")
            return 0 <= int(hh) <= 23 and 0 <= int(mm) <= 59

        def dfs(index: int, path: str) -> None:
            if index == 5:
                self.res += check(path)
                return
            if time[index] != "?":
                dfs(index + 1, path + time[index])
            else:
                for i in range(10):
                    dfs(index + 1, path + str(i))

        self.res = 0
        dfs(0, "")
        return self.res


class Solution:

    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        x_max = max(t[0] for t in towers)
        y_max = max(t[1] for t in towers)
        cx = cy = max_quality = 0
        for x in range(x_max + 1):
            for y in range(y_max + 1):
                quality = 0
                for tx, ty, q in towers:
                    d = (x - tx)**2 + (y - ty)**2
                    if d <= radius**2:
                        quality += int(q / (1 + d**0.5))
                if quality > max_quality:
                    cx, cy, max_quality = x, y, quality
        return [cx, cy]


class Solution:

    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        timeMap = defaultdict(list)
        for name, time in zip(keyName, keyTime):
            hour, minute = int(time[:2]), int(time[3:])
            timeMap[name].append(hour * 60 + minute)

        ans = []
        for name, times in timeMap.items():
            times.sort()
            if any(t2 - t1 <= 60 for t1, t2 in zip(times, times[2:])):
                ans.append(name)
        ans.sort()
        return ans
