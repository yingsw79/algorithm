#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

// https://atcoder.jp/contests/abc363/tasks/abc363_e

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, Y;
    cin >> h >> w >> Y;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    int n = h * w;
    DSU dsu(n + 1);
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i / w][i % w] < a[j / w][j % w]; });
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

    int j = 0;
    for (int i = 1; i <= Y; i++) {
        for (; j < n && a[idx[j] / w][idx[j] % w] <= i; j++) {
            int k = idx[j];
            int x = k / w, y = k % w;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || a[nx][ny] > i) {
                    continue;
                }
                dsu.merge(k, nx * w + ny);
            }
            if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
                dsu.merge(n, k);  // 虚拟节点n
            }
        }
        cout << n - dsu.size(n) + 1 << '\n';
    }

    return 0;
}