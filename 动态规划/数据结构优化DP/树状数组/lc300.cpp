#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-increasing-subsequence/

class Solution {
    typedef pair<int, int> PII;
    int tr[2010][2], m;

    void update(int x, int v, int cnt) {
        for (; x <= m; x += x & -x) {
            if (tr[x][0] < v) {
                tr[x][0] = v;
                tr[x][1] = cnt;
            } else if (tr[x][0] == v) {
                tr[x][1] += cnt;
            }
        }
    }

    PII query(int x) {
        PII res{0, 1};
        for (; x; x &= x - 1) {
            if (res.first < tr[x][0]) {
                res = {tr[x][0], tr[x][1]};
            } else if (res.first == tr[x][0]) {
                res.second += tr[x][1];
            }
        }
        return res;
    }

public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> nums = a;
        // 离散化
        sort(nums.begin(), nums.end());
        m = unique(nums.begin(), nums.end()) - nums.begin();
        for (int i = 0; i < n; i++)
            a[i] = lower_bound(nums.begin(), nums.begin() + m, a[i]) - nums.begin() + 1;

        memset(tr, 0, sizeof tr);
        for (int i = 0; i < n; i++) {
            PII t = query(a[i] - 1);
            update(a[i], t.first + 1, t.second);
        }
        return query(m).second;
    }
};

int main() {
    return 0;
}