# https://leetcode.cn/problems/count-days-spent-together/

class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        def mmdd2days(mmdd: str) -> int:
            mm, dd = map(int, mmdd.split("-"))
            return sum([31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31][: mm - 1]) + dd

        start1, end1, start2, end2 = map(mmdd2days, [arriveAlice, leaveAlice, arriveBob, leaveBob])
        return max(0, min(end1, end2) - max(start1, start2) + 1)  # 线段求交
