#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/contest/hhrc2022/problems/0Wx4Pc/

class Solution {
    static const int N = 20010, INF = 0x3f3f3f3f;
    int tr[N];

    void update(int x, int v) {
        for (; x < N; x += x & -x) tr[x] = min(tr[x], v);
    }

    int query(int x) {
        int res = INF;
        for (; x; x &= x - 1) res = min(res, tr[x]);
        return res;
    }

public:
    int longestESR(vector<int>& sales) {
        memset(tr, 0x3f, sizeof tr);
        for (int& x : sales) x = x > 8 ? 1 : -1;
        int n = sales.size(), res = 0;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + sales[i];
        for (int i = 0; i <= n; ++i) sum[i] += 10005;
        update(sum[0], 0);
        for (int i = 1; i <= n; ++i) {
            int t = query(sum[i] - 1);
            res = max(res, i - t);
            update(sum[i], i);
        }
        return res;
    }
};

int main() {
    return 0;
}