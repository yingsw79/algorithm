#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-rows-covered-by-columns/
// https://leetcode.cn/problems/increasing-subsequences/

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m);
        int k = 0;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                if (mat[i][j]) cnt++;
            row[i] = cnt;
            if (!cnt) k++;
        }

        int res = 0;
        for (int i = 0; i < 1 << n; ++i) {
            if (__builtin_popcount(i) == cols) {
                int cnt = k;
                vector<int> tmp = row;
                for (int j = 0; j < n; ++j) {
                    if (i >> j & 1) {
                        for (int k = 0; k < m; ++k) {
                            if (mat[k][j] && --tmp[k] == 0) cnt++;
                        }
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};

int main() {
    

    return 0;
}