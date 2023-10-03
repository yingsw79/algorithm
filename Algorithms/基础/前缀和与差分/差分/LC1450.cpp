#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/
// https://leetcode.cn/problems/number-of-flowers-in-full-bloom/description/?envType=daily-question&envId=2023-09-28

// 区间[l,r]加1,单点查询,不用离散化的方法！！！！！
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int lessStart = upper_bound(startTime.begin(), startTime.end(), queryTime) - startTime.begin();
        int lessEnd = lower_bound(endTime.begin(), endTime.end(), queryTime) - endTime.begin();
        return lessStart - lessEnd;
    }
};

// 差分需要离散化
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int maxEndTime = *max_element(endTime.begin(), endTime.end());
        if (queryTime > maxEndTime) {
            return 0;
        }
        vector<int> cnt(maxEndTime + 2);
        for (int i = 0; i < n; i++) {
            cnt[startTime[i]]++;
            cnt[endTime[i] + 1]--;
        }
        int ans = 0;
        for (int i = 0; i <= queryTime; i++) {
            ans += cnt[i];
        }
        return ans;
    }
};

int main() {
    return 0;
}