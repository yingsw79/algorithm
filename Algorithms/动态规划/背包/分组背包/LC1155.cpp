#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int n, int m, int t) {
        const int MOD = 1e9 + 7;
        int f[n + 1][t + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= t; j++)
                for (int k = 1; k <= min(j, m); k++)
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
        return f[n][t];
    }
};

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        int f[target + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 0; j--) {
                f[j] = 0;  //不能从f[i-1][j]转移,必须要选
                for (int u = 1; u <= k && u <= j; u++) {
                    f[j] = (f[j] + f[j - u]) % MOD;
                }
            }
        }
        return f[target];
    }
};

int main() {
    system("pause");
    return 0;
}