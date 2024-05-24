#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://atcoder.jp/contests/abc264/tasks/abc264_c

int a[15][15], b[15][15];
int m1, n1, m2, n2;

bool check() {
    for (int i = 0; i < 1 << m1; i++) {
        if (__builtin_popcount(i) == m2) {
            vector<int> row;
            for (int j = 0; j < m1; j++) {
                if (i >> j & 1) row.push_back(j);
            }
            for (int j = 0; j < 1 << n1; j++) {
                if (__builtin_popcount(j) == n2) {
                    vector<int> col;
                    for (int k = 0; k < n1; k++) {
                        if (j >> k & 1) col.push_back(k);
                    }
                    bool flag = true;
                    for (int u = 0; u < m2; u++)
                        for (int v = 0; v < n2; v++)
                            if (a[row[u]][col[v]] != b[u][v]) {
                                flag = false;
                                break;
                            }
                    if (flag) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &m1, &n1);
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            scanf("%d", &a[i][j]);

    scanf("%d%d", &m2, &n2);
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            scanf("%d", &b[i][j]);

    if (check()) puts("Yes");
    else puts("No");

    return 0;
}