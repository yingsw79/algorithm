#include <algorithm>
#include <cstring>
#include <iostream>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m, k;
PII match[N][N];
bool g[N][N], st[N][N];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool find(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > m) continue;
        if (g[a][b]) continue;
        if (st[a][b]) continue;

        st[a][b] = true;

        PII& t = match[a][b];
        if (t.x == 0 || find(t.x, t.y)) {
            t = {x, y};
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (g[i][j] || (i + j) % 2) continue;
            memset(st, 0, sizeof st);
            if (find(i, j)) res++;
        }

    cout << n * m - k - res << endl;

    return 0;
}
