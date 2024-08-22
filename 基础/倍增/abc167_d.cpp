#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://atcoder.jp/contests/abc167/tasks/abc167_d
// https://atcoder.jp/contests/abc367/tasks/abc367_e

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    i64 k;
    cin >> n >> k;
    int m = __lg(k) + 1;
    vector<vector<int>> f(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> f[i][0];
        f[i][0]--;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            f[j][i] = f[f[j][i - 1]][i - 1];
        }
    }
    int pos = 0;
    for (int i = 0; i < m; i++) {
        if (k >> i & 1) {
            pos = f[pos][i];
        }
    }
    cout << pos + 1;

    return 0;
}