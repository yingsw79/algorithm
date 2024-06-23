#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/
// https://leetcode.cn/problems/maximum-earnings-from-taxi/

class Solution {
    static const int N = 100010;
    int tr[N];

    void update(int x, int v) {
        for (; x < N; x += x & -x) tr[x] = max(tr[x], v);
    }

    int query(int x) {
        int res = 0;
        for (; x; x &= x - 1) res = max(res, tr[x]);
        return res;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> alls(n);
        for (int i = 0; i < n; ++i) alls[i] = {startTime[i], endTime[i], profit[i]};
        sort(alls.begin(), alls.end(), [](auto& a, auto& b) {
            return get<1>(a) < get<1>(b);
        });
        auto tmp = startTime;
        tmp.insert(tmp.end(), endTime.begin(), endTime.end());
        sort(tmp.begin(), tmp.end());
        int tot = unique(tmp.begin(), tmp.end()) - tmp.begin();
        for (int i = 0; i < n; ++i) {
            startTime[i] = lower_bound(tmp.begin(), tmp.begin() + tot, get<0>(alls[i])) - tmp.begin() + 1;
            endTime[i] = lower_bound(tmp.begin(), tmp.begin() + tot, get<1>(alls[i])) - tmp.begin() + 1;
            profit[i] = get<2>(alls[i]);
        }
        memset(tr, 0, sizeof tr);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int t = query(startTime[i]) + profit[i];
            res = max(res, t);
            update(endTime[i], t);
        }
        return res;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        array<int, 3> jobs[n];
        for (int i = 0; i < n; ++i)
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs, jobs + n, [](auto& a, auto& b) { return a[0] < b[0]; });  // 按照结束时间排序

        int f[n + 1];
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int j = upper_bound(jobs, jobs + i, array<int, 3>{jobs[i][1], INT_MAX}) - jobs;
            // 为什么是 j 不是 j+1：上面算的是 > 开始时间，-1 后得到 <= 开始时间，但由于还要 +1，抵消了
            f[i + 1] = max(f[i], f[j] + jobs[i][2]);
        }
        return f[n];
    }
};

int main() {
    return 0;
}