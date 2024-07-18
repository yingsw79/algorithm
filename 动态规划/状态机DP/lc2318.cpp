#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/number-of-distinct-roll-sequences/
// https://atcoder.jp/contests/abc362/tasks/abc362_e

class Solution {
public:
    const int MOD = 1e9 + 7;
    int distinctSequences(int n) {
        if (n == 1) return 6;
        int f[n + 1][7][7];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                if (i != j && gcd(i, j) == 1) f[2][i][j] = 1;

        for (int i = 3; i <= n; i++)
            for (int j = 1; j <= 6; j++)
                for (int k = 1; k <= 6; k++)
                    if (j != k && gcd(j, k) == 1)
                        for (int m = 1; m <= 6; m++)
                            if (m != j)
                                f[i][j][k] = (f[i][j][k] + f[i - 1][k][m]) % MOD;

        int res = 0;
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                res = (res + f[n][i][j]) % MOD;

        return res;
    }
};

int main() {
    system("pause");
    return 0;
}