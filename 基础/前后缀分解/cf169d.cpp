#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/2004/problem/D

const string s = "RGBY";

// 01 02 03 12 13 23
// 0  1  3  2  4  5
int index(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    return x + y * (y - 1) / 2;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<array<int, 2>> cl(n);
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < 2; j++) {
            cl[i][j] = s.find(t[j]);
        }
    }
    vector<array<int, 6>> L(n), R(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            L[i].fill(-1);
        } else {
            L[i] = L[i - 1];
        }
        L[i][index(cl[i][0], cl[i][1])] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            R[i].fill(-1);
        } else {
            R[i] = R[i + 1];
        }
        R[i][index(cl[i][0], cl[i][1])] = i;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x > y) {
            swap(x, y);
        }
        int res = INT_MAX;
        for (auto a : cl[x]) {
            for (auto b : cl[y]) {
                if (a == b) {
                    res = y - x;
                    continue;
                }
                int i = index(a, b);
                for (auto z : {R[x][i], L[y][i]}) {
                    if (z != -1) {
                        res = min(res, abs(x - z) + abs(y - z));
                    }
                }
            }
        }
        cout << (res == INT_MAX ? -1 : res) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}