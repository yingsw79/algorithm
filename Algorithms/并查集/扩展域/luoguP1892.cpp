#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P1892

const int N = 2010;
int p[N];
int n, m;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++) p[i] = i;

    while (m--) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'F') {
            p[find(x)] = find(y);
            // p[find(x + n)] = find(y + n);
        } else {
            p[find(x + n)] = find(y);
            p[find(y + n)] = find(x);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) res++;
    }

    cout << res << endl;

    return 0;
}