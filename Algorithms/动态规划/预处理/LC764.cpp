#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> g(n, vector<int>(n, 1));
        for (auto& mine : mines) g[mine[0]][mine[1]] = 0;
        int L[n][n], R[n][n], U[n][n], D[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                L[i][j] = g[i][j];
                if (j > 0 && g[i][j]) L[i][j] += L[i][j - 1];
                U[j][i] = g[j][i];
                if (j > 0 && g[j][i]) U[j][i] += U[j - 1][i];
            }
            for (int j = n - 1; j >= 0; --j) {
                R[i][j] = g[i][j];
                if (j + 1 < n && g[i][j]) R[i][j] += R[i][j + 1];
                D[j][i] = g[j][i];
                if (j + 1 < n && g[j][i]) D[j][i] += D[j + 1][i];
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res = max(res, min({L[i][j], R[i][j], U[i][j], D[i][j]}));
        return res;
    }
};

int main() {
    return 0;
}