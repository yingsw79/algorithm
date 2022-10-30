from collections import Counter
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



