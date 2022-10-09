#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n][k];
        memset(f, 0, sizeof f);
        f[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                for (int r = 0; r < k; ++r) {  // 同余
                    int t = (grid[i][j] + r) % k;
                    if (i >= 1) f[i][j][t] = (f[i][j][t] + f[i - 1][j][r]) % MOD;
                    if (j >= 1) f[i][j][t] = (f[i][j][t] + f[i][j - 1][r]) % MOD;
                }
            }
        return f[m - 1][n - 1][0];
    }
};

int main() {
    

    return 0;
}