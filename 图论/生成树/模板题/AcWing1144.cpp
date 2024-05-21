#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1146/

const int N = 1010;
int p[N * N];
int m, n;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m * n; i++) p[i] = i;
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int a = (x1 - 1) * n + y1 - 1, b = (x2 - 1) * n + y2 - 1;
        p[find(a)] = find(b);
    }

    int res = 0;
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < n; j++) {
            int a = i * n + j, b = (i + 1) * n + j;
            a = find(a), b = find(b);
            if (a == b) continue;
            p[a] = b;
            res++;
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n - 1; j++) {
            int a = i * n + j, b = i * n + j + 1;
            a = find(a), b = find(b);
            if (a == b) continue;
            p[a] = b;
            res += 2;
        }

    cout << res << endl;
    return 0;
}