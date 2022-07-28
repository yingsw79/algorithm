#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 110;
int n, t;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
PII match[N][N];
bool g[N][N], st[N][N];

bool find(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > n) continue;
        if (st[a][b] || g[a][b]) continue;
        st[a][b] = true;
        PII& t = match[a][b];
        if (!t.first || find(t.first, t.second)) {
            t = {x, y};
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &t);
    
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = true;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!g[i][j] && (i + j) % 2) {
                memset(st, 0, sizeof st);
                if (find(i, j)) res++;
            }
        }
    }
    printf("%d\n", res);

    return 0;
}