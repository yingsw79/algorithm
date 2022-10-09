#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-deletions-on-a-string/

class Solution {
public:
    using ULL = unsigned long long;
    vector<ULL> h, p;

    ULL get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    int deleteString(string s) {
        int n = s.length();
        h.resize(n + 1), p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {  // 字符串哈希
            h[i] = h[i - 1] * 131 + s[i - 1];
            p[i] = p[i - 1] * 131;
        }
        int f[n + 1];
        memset(f, 0xcf, sizeof f);
        f[1] = 0;
        vector<vector<int>> pre(n + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = i; j - i + 1 <= (n - i + 1) / 2; ++j)
                if (get(i, j) == get(j + 1, j * 2 + 1 - i))
                    pre[j + 1].push_back(i);  // 预处理

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int x : pre[i])  // 转移
                f[i] = max(f[i], f[x] + 1);
            res = max(res, f[i]);
        }
        return res + 1;
    }
};

int main() {
    return 0;
}