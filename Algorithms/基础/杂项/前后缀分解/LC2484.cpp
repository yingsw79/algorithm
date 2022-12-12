#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-palindromic-subsequences/

typedef long long LL;
const int N = 10010, MOD = 1e9 + 7;

int s[N][10][10], r[N][10][10];

class Solution {
public:
    int countPalindromes(string str) {
        int n = str.size();
        int cnt[10] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    s[i][j][k] = s[i - 1][j][k];
                }
            }

            int y = str[i - 1] - '0';
            for (int j = 0; j < 10; j++)
                s[i][j][y] += cnt[j];

            cnt[y]++;
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                r[n + 1][i][j] = 0;
            }
        }

        memset(cnt, 0, sizeof cnt);
        for (int i = n; i; i--) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    r[i][j][k] = r[i + 1][j][k];
                }
            }

            int y = str[i - 1] - '0';
            for (int j = 0; j < 10; j++)
                r[i][y][j] += cnt[j];

            cnt[y]++;
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    res = (res + (LL)s[i - 1][j][k] * r[i + 1][k][j]) % MOD;
                }
            }
        }

        return res;
    }
};

int main() {
    return 0;
}