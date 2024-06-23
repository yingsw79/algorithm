#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii/

class Solution {
    int tr[2000010], m;

    void update(int x, int v) {
        for (; x <= m; x += x & -x) tr[x] = max(tr[x], v);
    }

    int query(int x) {
        int res = 0;
        for (; x; x &= x - 1) res = max(res, tr[x]);
        return res;
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& e1, const auto& e2) {
            return e1[1] < e2[1];
        });
        int n = events.size();
        m = 0;
        int nums[n * 2], st[n], ed[n];
        for (auto& e : events) {
            nums[m++] = e[0];
            nums[m++] = e[1];
        }
        sort(nums, nums + m);
        m = unique(nums, nums + m) - nums;
        for (int i = 0; i < n; ++i) {
            st[i] = lower_bound(nums, nums + m, events[i][0]) - nums + 1;
            ed[i] = lower_bound(nums, nums + m, events[i][1]) - nums + 1;
        }
        int f[k + 1][n], res = 0;
        memset(f, 0, sizeof f);
        for (int i = 1; i <= k; ++i) {
            // for (int j = 0; j <= m; ++j) tr[j] = 0;
            for (int j = 0; j < n; ++j) {
                f[i][j] = query(st[j] - 1) + events[j][2];
                res = max(res, f[i][j]);
                update(ed[j], f[i - 1][j]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}