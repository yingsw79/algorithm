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
    int tr[2510], m;

    void update(int x, int v) {
        for (; x <= m; x += x & -x) tr[x] = max(tr[x], v);
    }

    int query(int x) {  // 区间[1,x]上的最大值
        int res = 0;
        for (; x; x &= x - 1) res = max(res, tr[x]);
        return res;
    }

public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> nums = a;
        sort(nums.begin(), nums.end());
        m = unique(nums.begin(), nums.end()) - nums.begin();
        for (int i = 0; i < n; i++)
            a[i] = lower_bound(nums.begin(), nums.begin() + m, a[i]) - nums.begin() + 1;
        memset(tr, 0, sizeof tr);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int v = query(a[i] - 1) + 1;
            res = max(res, v);
            update(a[i], v);
        }
        return res;
    }
};

int main() {
    return 0;
}