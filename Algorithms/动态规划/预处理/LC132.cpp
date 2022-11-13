#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool g[n + 1][n + 1];
        memset(g, 0, sizeof g);
        for (int len = 1; len <= n; ++len)
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                if (s[i - 1] == s[j - 1] && (len <= 2 || g[i + 1][j - 1])) g[i][j] = true;
            }
        vector<int> f(n + 1);
        iota(f.begin(), f.end(), -1);
        for (int i = 1; i <= n; ++i)
            for (int j = i; j; --j)
                if (g[j][i]) f[i] = min(f[i], f[j - 1] + 1);
        return f[n];
    }
};

int main() {
    return 0;
}