#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-balanced-subsequence-sum/

class Solution {
    using LL = long long;
    vector<LL> tr;

    void update(int x, LL v) {
        for (; x < tr.size(); x += x & -x) tr[x] = max(tr[x], v);
    }

    LL query(int x) {
        LL res = LLONG_MIN;
        for (; x; x &= x - 1) res = max(res, tr[x]);
        return res;
    }

public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        auto a = nums;
        for (int i = 0; i < n; i++) a[i] -= i;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        tr = vector<LL>(a.size() + 1, LLONG_MIN);
        LL res = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            int x = lower_bound(a.begin(), a.end(), nums[i] - i) - a.begin() + 1;
            LL v = max(query(x), 0ll) + nums[i];
            update(x, v);
            res = max(res, v);
        }
        return res;
    }
};

int main() {
    return 0;
}